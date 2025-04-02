#include "Use_arch_btwRegisterInfo.h"
#include "Use_arch_btw.h"
#include "Use_arch_btwFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "Use_arch_btwGenRegisterInfo.inc"

Use_arch_btwRegisterInfo::Use_arch_btwRegisterInfo()
    : Use_arch_btwGenRegisterInfo(Use_arch_btw::R0) {
  USE_ARCH_BTW_DUMP_GREEN
}

const MCPhysReg *
Use_arch_btwRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  USE_ARCH_BTW_DUMP_GREEN
  return CSR_Use_arch_btw_SaveList;
}

BitVector
Use_arch_btwRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  USE_ARCH_BTW_DUMP_GREEN
  Use_arch_btwFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Use_arch_btw::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Use_arch_btw::R2);
  }
  return Reserved;
}

bool Use_arch_btwRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool Use_arch_btwRegisterInfo::eliminateFrameIndex(
    MachineBasicBlock::iterator II, int SPAdj, unsigned FIOperandNum,
    RegScavenger *RS) const {
  USE_ARCH_BTW_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register
Use_arch_btwRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  USE_ARCH_BTW_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Use_arch_btw::R2 : Use_arch_btw::R1;
}

const uint32_t *
Use_arch_btwRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                               CallingConv::ID CC) const {
  USE_ARCH_BTW_DUMP_GREEN
  return CSR_Use_arch_btw_RegMask;
}
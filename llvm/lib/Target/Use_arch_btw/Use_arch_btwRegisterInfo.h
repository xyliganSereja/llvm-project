#pragma once

#define GET_REGINFO_HEADER
#include "Use_arch_btwGenRegisterInfo.inc"

namespace llvm {

class TargetInstrInfo;
class Use_arch_btwSubtarget;

struct Use_arch_btwRegisterInfo : public Use_arch_btwGenRegisterInfo {
public:
  Use_arch_btwRegisterInfo();

  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;

  const uint32_t *getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID CC) const override;

  BitVector getReservedRegs(const MachineFunction &MF) const override;

  bool requiresRegisterScavenging(const MachineFunction &MF) const override;

  bool eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;

  // Debug information queries.
  Register getFrameRegister(const MachineFunction &MF) const override;
};

} // end namespace llvm

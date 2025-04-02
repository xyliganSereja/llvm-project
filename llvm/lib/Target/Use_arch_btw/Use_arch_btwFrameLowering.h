#pragma once

#include "Use_arch_btw.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class Use_arch_btwSubtarget;

class Use_arch_btwFrameLowering : public TargetFrameLowering {
public:
  Use_arch_btwFrameLowering(const Use_arch_btwSubtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0),
        STI(STI) {
    USE_ARCH_BTW_DUMP_GREEN
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}

  /// hasFP - Return true if the specified function should have a dedicated
  /// frame pointer register. For most targets this is true only if the function
  /// has variable sized allocas or if frame pointer elimination is disabled.
  bool hasFPImpl(const MachineFunction &MF) const override { return false; }

private:
  const Use_arch_btwSubtarget &STI;
};

} // namespace llvm

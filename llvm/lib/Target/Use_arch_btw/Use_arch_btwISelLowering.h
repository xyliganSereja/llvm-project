#pragma once

#include "Use_arch_btw.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class Use_arch_btwSubtarget;
class Use_arch_btwTargetMachine;

namespace Use_arch_btwISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};
} // namespace Use_arch_btwISD

class Use_arch_btwTargetLowering : public TargetLowering {
public:
  explicit Use_arch_btwTargetLowering(const TargetMachine &TM,
                                      const Use_arch_btwSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  Use_arch_btwSubtarget const &getSubtarget() const { return STI; }

private:
  const Use_arch_btwSubtarget &STI;
};

} // end namespace llvm

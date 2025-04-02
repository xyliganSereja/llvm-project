#pragma once

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace Use_arch_btwOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace Use_arch_btwOp

} // end namespace llvm
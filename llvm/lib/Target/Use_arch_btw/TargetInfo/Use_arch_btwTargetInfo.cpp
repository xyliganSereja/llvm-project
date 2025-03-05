#include "TargetInfo/Use_arch_btwTargetInfo.h"
#include "Use_arch_btw.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheUse_arch_btwTarget() {
  USE_ARCH_BTW_DUMP_YELLOW
  static Target TheUse_arch_btwTarget;
  return TheUse_arch_btwTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeUse_arch_btwTargetInfo() {
  USE_ARCH_BTW_DUMP_YELLOW
  RegisterTarget<Triple::use_arch_btw> X(getTheUse_arch_btwTarget(), "use_arch_btw",
                                "Simulator target for LLVM course", "USE_ARCH_BTW");
}
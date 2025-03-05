#include "Use_arch_btwTargetMachine.h"
#include "Use_arch_btw.h"
#include "TargetInfo/Use_arch_btwTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeUse_arch_btwTarget() {
  // Register the target.
  USE_ARCH_BTW_DUMP_CYAN
  RegisterTargetMachine<Use_arch_btwTargetMachine> A(getTheUse_arch_btwTarget());
}

Use_arch_btwTargetMachine::Use_arch_btwTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT,
                        CPU, FS, Options, Reloc::Static,
                        getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  USE_ARCH_BTW_DUMP_CYAN
}
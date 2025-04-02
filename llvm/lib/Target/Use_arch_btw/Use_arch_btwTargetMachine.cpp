#include "Use_arch_btwTargetMachine.h"
#include "TargetInfo/Use_arch_btwTargetInfo.h"
#include "Use_arch_btw.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"

#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeUse_arch_btwTarget() {
  // Register the target.
  USE_ARCH_BTW_DUMP_CYAN
  RegisterTargetMachine<Use_arch_btwTargetMachine> A(
      getTheUse_arch_btwTarget());
}

Use_arch_btwTargetMachine::Use_arch_btwTargetMachine(
    const Target &T, const Triple &TT, StringRef CPU, StringRef FS,
    const TargetOptions &Options, std::optional<Reloc::Model> RM,
    std::optional<CodeModel::Model> CM, CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  USE_ARCH_BTW_DUMP_CYAN
  initAsmInfo();
}

namespace {
/// Use_arch_btw Code Generator Pass Configuration Options.
class Use_arch_btwPassConfig : public TargetPassConfig {
public:
  Use_arch_btwPassConfig(Use_arch_btwTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  Use_arch_btwTargetMachine &getUse_arch_btwTargetMachine() const {
    return getTM<Use_arch_btwTargetMachine>();
  }

  bool addInstSelector() override {
    USE_ARCH_BTW_DUMP_CYAN
    addPass(createUse_arch_btwISelDag(getUse_arch_btwTargetMachine(),
                                      getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *
Use_arch_btwTargetMachine::createPassConfig(PassManagerBase &PM) {
  USE_ARCH_BTW_DUMP_CYAN
  return new Use_arch_btwPassConfig(*this, PM);
}

TargetLoweringObjectFile *SimTargetMachine::getObjFileLowering() const {
  SIM_DUMP_CYAN
  return TLOF.get();
}
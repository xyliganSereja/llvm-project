#include "MCTargetDesc/Use_arch_btwInfo.h"
#include "TargetInfo/Use_arch_btwTargetInfo.h"
#include "Use_arch_btw.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "Use_arch_btwGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "Use_arch_btwGenInstrInfo.inc"

static MCRegisterInfo *createUse_arch_btwMCRegisterInfo(const Triple &TT) {
  USE_ARCH_BTW_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitUse_arch_btwMCRegisterInfo(X, Use_arch_btw::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeUse_arch_btwTargetMC() {
  USE_ARCH_BTW_DUMP_MAGENTA
  Target &TheUse_arch_btwTarget = getTheUse_arch_btwTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheUse_arch_btwTarget,
                                    createUse_arch_btwMCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(TheUse_arch_btwTarget,
                                      createUse_arch_btwMCInstrInfo);
}
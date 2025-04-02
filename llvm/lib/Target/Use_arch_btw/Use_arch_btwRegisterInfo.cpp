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
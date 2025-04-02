#include "Use_arch_btwSubtarget.h"
#include "Use_arch_btw.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "use_arch_btw-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "Use_arch_btwGenSubtargetInfo.inc"

Use_arch_btwSubtarget::Use_arch_btwSubtarget(const Triple &TT,
                                             const std::string &CPU,
                                             const std::string &FS,
                                             const TargetMachine &TM)
    : Use_arch_btwGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS),
      TLInfo(TM, *this) {
  USE_ARCH_BTW_DUMP_CYAN
}
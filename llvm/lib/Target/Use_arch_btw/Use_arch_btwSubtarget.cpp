#include "Use_arch_btwSubtarget.h"
#include "Use_arch_btw.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "use_arch_btw-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "Use_arch_btwGenSubtargetInfo.inc"

Use_arch_btwSubtarget::Use_arch_btwSubtarget(const StringRef &CPU,
                                             const StringRef &TuneCPU,
                                             const StringRef &FS,
                                             const TargetMachine &TM)
    : Use_arch_btwGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  USE_ARCH_BTW_DUMP_CYAN
}
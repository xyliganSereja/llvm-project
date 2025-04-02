#include "Use_arch_btwInstrInfo.h"
#include "Use_arch_btw.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "Use_arch_btwGenInstrInfo.inc"

#define DEBUG_TYPE "Use_arch_btw-inst-info"

Use_arch_btwInstrInfo::Use_arch_btwInstrInfo() : Use_arch_btwGenInstrInfo() { USE_ARCH_BTW_DUMP_GREEN }
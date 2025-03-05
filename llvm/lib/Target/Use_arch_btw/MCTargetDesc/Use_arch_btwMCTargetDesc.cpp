#include "../Use_arch_btw.h"
#include "llvm/Support/raw_ostream.h"

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeUse_arch_btwTargetMC() { USE_ARCH_BTW_DUMP_MAGENTA }
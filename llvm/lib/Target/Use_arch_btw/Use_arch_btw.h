#ifndef LLVM_LIB_TARGET_USE_ARCH_BTW_USE_ARCH_BTW_H
#define LLVM_LIB_TARGET_USE_ARCH_BTW_USE_ARCH_BTW_H

#include "MCTargetDesc/Use_arch_btw.h"
#include "llvm/Support/raw_ostream.h"

#define USE_ARCH_BTW_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define USE_ARCH_BTW_DUMP(Color) {}

#define USE_ARCH_BTW_DUMP_RED USE_ARCH_BTW_DUMP(llvm::raw_ostream::RED)
#define USE_ARCH_BTW_DUMP_GREEN USE_ARCH_BTW_DUMP(llvm::raw_ostream::GREEN)
#define USE_ARCH_BTW_DUMP_YELLOW USE_ARCH_BTW_DUMP(llvm::raw_ostream::YELLOW)
#define USE_ARCH_BTW_DUMP_CYAN USE_ARCH_BTW_DUMP(llvm::raw_ostream::CYAN)
#define USE_ARCH_BTW_DUMP_MAGENTA USE_ARCH_BTW_DUMP(llvm::raw_ostream::MAGENTA)
#define USE_ARCH_BTW_DUMP_WHITE USE_ARCH_BTW(llvm::raw_ostream::WHITE)

#endif // LLVM_LIB_TARGET_USE_ARCH_BTW_USE_ARCH_BTW_H
#ifndef LLVM_LIB_TARGET_USE_ARCH_BTW_USE_ARCH_BTWREGISTERINFO_H
#define LLVM_LIB_TARGET_USE_ARCH_BTW_USE_ARCH_BTWREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "Use_arch_btwGenRegisterInfo.inc"

namespace llvm {

struct Use_arch_btwRegisterInfo : public Use_arch_btwGenRegisterInfo {
public:
  Use_arch_btwRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_USE_ARCH_BTW_USE_ARCH_BTWREGISTERINFO_H
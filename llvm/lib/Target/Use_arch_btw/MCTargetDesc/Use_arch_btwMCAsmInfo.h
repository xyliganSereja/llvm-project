#pragma once

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class Use_arch_btwELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit Use_arch_btwELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm
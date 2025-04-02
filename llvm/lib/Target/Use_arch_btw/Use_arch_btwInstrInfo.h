#pragma once

#include "MCTargetDesc/Use_arch_btwInfo.h"
#include "Use_arch_btwRegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "Use_arch_btwGenInstrInfo.inc"

namespace llvm {

class Use_arch_btwSubtarget;

class Use_arch_btwInstrInfo : public Use_arch_btwGenInstrInfo {
public:
  Use_arch_btwInstrInfo();
};

} // end namespace llvm
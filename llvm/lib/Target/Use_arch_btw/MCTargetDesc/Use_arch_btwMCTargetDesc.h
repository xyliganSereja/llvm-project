
#pragma once

#include <memory>

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createUse_arch_btwMCCodeEmitter(const MCInstrInfo &MCII,
                                               MCContext &Ctx);
MCAsmBackend *createUse_arch_btwAsmBackend(const Target &T,
                                           const MCSubtargetInfo &STI,
                                           const MCRegisterInfo &MRI,
                                           const MCTargetOptions &Options);
MCAsmBackend *createSimAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createSimELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for Use_arch_btw registers.  This defines a mapping
// from register name to register number.
//
#define GET_REGINFO_ENUM
#include "Use_arch_btwGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "Use_arch_btwGenInstrInfo.inc"

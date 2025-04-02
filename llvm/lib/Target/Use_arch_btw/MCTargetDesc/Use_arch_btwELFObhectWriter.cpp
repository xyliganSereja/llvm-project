#include "MCTargetDesc/Use_arch_btwMCTargetDesc.h"
#include "Use_arch_btw.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class Use_arch_btwELFObjectWriter : public MCELFObjectTargetWriter {
public:
  Use_arch_btwELFObjectWriter(bool Is64Bit, uint8_t OSABI)
      : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_USE_ARCH_BTW,
                                /*HasRelocationAddend*/ true) {}

  ~Use_arch_btwELFObjectWriter() override = default;

protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override;

  bool needsRelocateWithSymbol(const MCValue &Val, const MCSymbol &Sym,
                               unsigned Type) const override;
};
} // namespace

unsigned Use_arch_btwELFObjectWriter::getRelocType(MCContext &Ctx,
                                                   const MCValue &Target,
                                                   const MCFixup &Fixup,
                                                   bool IsPCRel) const {
  MCFixupKind Kind = Fixup.getKind();
  if (Kind >= FirstLiteralRelocationKind)
    return Kind - FirstLiteralRelocationKind;

  llvm_unreachable("Unimplemented fixup -> relocation");
}

bool Use_arch_btwELFObjectWriter::needsRelocateWithSymbol(const MCValue &,
                                                          const MCSymbol &,
                                                          unsigned Type) const {
  return false;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createUse_arch_btwELFObjectWriter(bool Is64Bit, uint8_t OSABI) {
  return std::make_unique<Use_arch_btwELFObjectWriter>(Is64Bit, OSABI);
}
#include "Use_arch_btwMCAsmInfo.h"
#include "Use_arch_btw.h"

using namespace llvm;

Use_arch_btwELFMCAsmInfo::Use_arch_btwELFMCAsmInfo(const Triple &TT) {
  USE_ARCH_BTW_DUMP_MAGENTA
  SupportsDebugInformation = false;
  Data16bitsDirective = "\t.short\t";
  Data32bitsDirective = "\t.word\t";
  Data64bitsDirective = nullptr;
  ZeroDirective = "\t.space\t";
  CommentString = ";";

  UsesELFSectionDirectiveForBSS = false;
  AllowAtInName = true;
  HiddenVisibilityAttr = MCSA_Invalid;
  HiddenDeclarationVisibilityAttr = MCSA_Invalid;
  ProtectedVisibilityAttr = MCSA_Invalid;

  ExceptionsType = ExceptionHandling::None;
}
#include "Use_arch_btw.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;

static constexpr Builtin::Info BuiltinInfo[] = {
    #define BUILTIN(ID, TYPE, ATTRS)                                               \
      {#ID, TYPE, ATTRS, nullptr, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
    #include "clang/Basic/BuiltinsUse_arch_btw.def"
    };

void Use_arch_btwTargetInfo::getTargetDefines(const LangOptions &Opts,
                                    MacroBuilder &Builder) const {
    Builder.defineMacro("__sim__");
}

ArrayRef<Builtin::Info> Use_arch_btwTargetInfo::getTargetBuiltins() const {
    return llvm::ArrayRef(BuiltinInfo,
        clang::Use_arch_btw::LastTSBuiltin - Builtin::FirstTSBuiltin);
}
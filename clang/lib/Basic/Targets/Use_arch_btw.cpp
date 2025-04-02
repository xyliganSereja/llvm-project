#include "Use_arch_btw.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void Use_arch_btwTargetInfo::getTargetDefines(const LangOptions &Opts,
                                    MacroBuilder &Builder) const {
    Builder.defineMacro("__sim__");
}

ArrayRef<Builtin::Info> Use_arch_btwTargetInfo::getTargetBuiltins() const {
    return std::nullopt;
}
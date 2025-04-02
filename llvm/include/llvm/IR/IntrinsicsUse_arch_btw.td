let TargetPrefix = "use_arch_btw" in {  // All intrinsics start with "llvm.use_arch_btw.".
  
def int_use_arch_btw_putpixel:
Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

def int_use_arch_btw_flush:
Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

} // TargetPrefix = "use_arch_btw"
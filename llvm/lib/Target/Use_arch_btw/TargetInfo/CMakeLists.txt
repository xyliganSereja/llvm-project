add_llvm_component_library(LLVMUse_arch_btwInfo
  Use_arch_btwTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Use_arch_btw
  )
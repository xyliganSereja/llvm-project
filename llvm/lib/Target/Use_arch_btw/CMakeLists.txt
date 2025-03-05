add_llvm_component_group(Use_arch_btw)

add_llvm_target(Use_arch_btwCodeGen
  Use_arch_btwTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  SimInfo

  ADD_TO_COMPONENT
  Use_arch_btw
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
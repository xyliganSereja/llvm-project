add_llvm_component_group(Use_arch_btw)

set(LLVM_TARGET_DEFINITIONS Use_arch_btw.td)
 
tablegen(LLVM Use_arch_btwGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM Use_arch_btwGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM Use_arch_btwGenSubtargetInfo.inc -gen-subtarget)
 
add_public_tablegen_target(Use_arch_btwCommonTableGen)

add_llvm_target(Use_arch_btwCodeGen
  Use_arch_btwTargetMachine.cpp
  Use_arch_btwRegisterInfo.cpp
  Use_arch_btwInstr.cpp
  Use_arch_btwSubtarget.cpp

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
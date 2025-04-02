add_llvm_component_library(LLVMUse_arch_btwDesc
    Use_arch_btwMCTargetDesc.cpp
    Use_arch_btwMCAsmInfo.cpp
    Use_arch_btwInstPrinter.cpp
    Use_arch_btwMCCodeEmitter.cpp
    Use_arch_btwAsmBackend.cpp
    Use_arch_btwELFObjectWriter.cpp

    LINK_COMPONENTS
    MC
    Use_arch_btwInfo
    Support

    ADD_TO_COMPONENT
    Use_arch_btw
)
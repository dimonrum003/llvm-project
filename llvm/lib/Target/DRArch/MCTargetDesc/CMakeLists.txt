add_llvm_component_library(LLVMDRArchDesc
  DRArchMCTargetDesc.cpp
  DRArchMCAsmInfo.cpp

  LINK_COMPONENTS
  MC
  Support
  DRArchInfo

  ADD_TO_COMPONENT
  DRArch
 )

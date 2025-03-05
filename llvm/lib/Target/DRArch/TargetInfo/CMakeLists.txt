add_llvm_component_library(LLVMDRArchInfo
  DRArchTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  DRArch
  )

add_llvm_component_group(DRArch)

add_llvm_target(DRArchCodeGen
  DRArchTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  DRArchInfo

  ADD_TO_COMPONENT
  DRArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)

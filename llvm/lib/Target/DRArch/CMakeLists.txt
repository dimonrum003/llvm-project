add_llvm_component_group(DRArch)

set(LLVM_TARGET_DEFINITIONS DRArch.td)
 
tablegen(LLVM DRArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM DRArchGenInstrInfo.inc -gen-instr-info)
 
add_public_tablegen_target(DRArchCommonTableGen)
 
add_llvm_target(DRArchCodeGen
  DRArchTargetMachine.cpp
  DRArchRegisterInfo.cpp
  DRArchInstrInfo.cpp

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

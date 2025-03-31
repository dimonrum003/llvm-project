add_llvm_component_group(DRArch)

set(LLVM_TARGET_DEFINITIONS DRArch.td)
 
tablegen(LLVM DRArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM DRArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM DRArchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM DRArchGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM DRArchGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM DRArchGenCallingConv.inc -gen-callingconv)
tablegen(LLVM DRArchGenAsmWriter.inc -gen-asm-writer)
 
add_public_tablegen_target(DRArchCommonTableGen)
 
add_llvm_target(DRArchCodeGen
  DRArchTargetMachine.cpp
  DRArchRegisterInfo.cpp
  DRArchInstrInfo.cpp
  DRArchSubtarget.cpp
  DRArchAsmPrinter.cpp
  DRArchISelDagToDag.cpp
  DRArchISelLowering.cpp
  DRArchMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  DRArchInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  DRArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)

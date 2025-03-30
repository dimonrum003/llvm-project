#ifndef LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCTARGETDESC_H

// Defines symbolic names for DRArch registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "DRArchGenRegisterInfo.inc"

// Defines symbolic names for the DRArch instructions.
#define GET_INSTRINFO_ENUM
#include "DRArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCTARGETDESC_H

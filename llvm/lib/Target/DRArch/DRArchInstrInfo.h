#ifndef LLVM_LIB_TARGET_DRARCH_DRARCHINSTRINFO_H
#define LLVM_LIB_TARGET_DRARCH_DRARCHINSTRINFO_H

#include "DRArchRegisterInfo.h"
#include "MCTargetDesc/DRArchInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "DRArchGenInstrInfo.inc"

namespace llvm {

class DRArchSubtarget;

class DRArchInstrInfo : public DRArchGenInstrInfo {
public:
  DRArchInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_DRARCH_DRARCHINSTRINFO_H

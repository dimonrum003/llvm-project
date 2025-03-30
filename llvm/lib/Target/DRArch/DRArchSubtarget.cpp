#include "DRArchSubtarget.h"
#include "DRArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "drarch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "DRArchGenSubtargetInfo.inc"

DRArchSubtarget::DRArchSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : DRArchGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  DRARCH_DUMP_CYAN
}

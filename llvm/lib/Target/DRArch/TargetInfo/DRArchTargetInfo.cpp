#include "TargetInfo/DRArchTargetInfo.h"
#include "DRArch.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheDRArchTarget() {
  DRARCH_DUMP_YELLOW
  static Target TheDRArchTarget;
  return TheDRArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeDRArchTargetInfo() {
  DRARCH_DUMP_YELLOW
  RegisterTarget<Triple::drarch> X(getTheDRArchTarget(), "drarch",
                                "DRArch target for LLVM course", "DRARCH");
}

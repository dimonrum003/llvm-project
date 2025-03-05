#include "TargetInfo/DRArchTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheDRArchTarget() {
  static Target TheDRArchTarget;
  return TheDRArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeDRArchTargetInfo() {
  RegisterTarget<Triple::drarch> X(getTheDRArchTarget(), "drarch", "DRArch 32",
                                   "DRARCH");
}

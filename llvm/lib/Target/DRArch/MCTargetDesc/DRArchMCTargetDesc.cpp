#include "DRArch.h"
#include "TargetInfo/DRArchTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "DRArchGenRegisterInfo.inc"

static MCRegisterInfo *createDRArchMCRegisterInfo(const Triple &TT) {
    DRARCH_DUMP_MAGENTA
    MCRegisterInfo *X = new MCRegisterInfo();
    InitDRArchMCRegisterInfo(X, DRArch::R0);

    return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeDRArchTargetMC() {
    DRARCH_DUMP_MAGENTA
    Target &TheDRArchTarget = getTheDRArchTarget();
    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(TheDRArchTarget, createDRArchMCRegisterInfo);
}

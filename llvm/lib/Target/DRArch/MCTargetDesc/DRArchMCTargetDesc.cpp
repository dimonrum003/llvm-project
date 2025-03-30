#include "MCTargetDesc/DRArchInfo.h"
#include "DRArch.h"
#include "TargetInfo/DRArchTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "DRArchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "DRArchGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "DRArchGenSubtargetInfo.inc"

static MCRegisterInfo *createDRArchMCRegisterInfo(const Triple &TT) {
  DRARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitDRArchMCRegisterInfo(X, DRArch::R0);
  return X;
}

static MCInstrInfo *createDRArchMCInstrInfo() {
  DRARCH_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitDRArchMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createDRArchMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  DRARCH_DUMP_MAGENTA
  return createDRArchMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeDRArchTargetMC() {
  DRARCH_DUMP_MAGENTA
  Target &TheDRArchTarget = getTheDRArchTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheDRArchTarget, createDRArchMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheDRArchTarget, createDRArchMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheDRArchTarget,
                                          createDRArchMCSubtargetInfo);
}

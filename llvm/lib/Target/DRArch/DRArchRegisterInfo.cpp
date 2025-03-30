#include "DRArchRegisterInfo.h"
#include "DRArch.h"
#include "DRArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "DRArchGenRegisterInfo.inc"

DRArchRegisterInfo::DRArchRegisterInfo() : DRArchGenRegisterInfo(DRArch::R0) {
    DRARCH_DUMP_GREEN
}

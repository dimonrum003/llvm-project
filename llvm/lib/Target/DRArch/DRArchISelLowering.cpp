#include "DRArchISelLowering.h"
#include "DRArch.h"
#include "DRArchRegisterInfo.h"
#include "DRArchSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "DRArch-lower"

using namespace llvm;

DRArchTargetLowering::DRArchTargetLowering(const TargetMachine &TM,
                                     const DRArchSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  DRARCH_DUMP_RED
  addRegisterClass(MVT::i32, &DRArch::GPRRegClass);
}

const char *DRArchTargetLowering::getTargetNodeName(unsigned Opcode) const {
  DRARCH_DUMP_RED
  switch (Opcode) {
  case DRArchISD::CALL:
    return "DRArchISD::CALL";
  case DRArchISD::RET:
    return "DRArchISD::RET";
  }
  return nullptr;
}

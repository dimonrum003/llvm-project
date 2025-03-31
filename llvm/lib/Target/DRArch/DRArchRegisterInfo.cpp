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

const MCPhysReg *
DRArchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  DRARCH_DUMP_GREEN
  return CSR_DRArch_SaveList;
}

BitVector DRArchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  DRARCH_DUMP_GREEN
  DRArchFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(DRArch::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(DRArch::R2);
  }
  return Reserved;
}

bool DRArchRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool DRArchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  DRARCH_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register DRArchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  DRARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? DRArch::R2 : DRArch::R1;
}

const uint32_t *
DRArchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  DRARCH_DUMP_GREEN
  return CSR_DRArch_RegMask;
}

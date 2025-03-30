include "llvm/Target/Target.td"
include "DRArchRegisterInfo.td"
include "DRArchInstrInfo.td"

def DRArchInstrInfo : InstrInfo;
def DRArch : Target {
  let InstructionSet = DRArchInstrInfo;
}

include "llvm/Target/Target.td"
include "DRArchRegisterInfo.td"
include "DRArchInstrInfo.td"
include "DRArchCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def DRArchInstrInfo : InstrInfo;
def DRArch : Target {
  let InstructionSet = DRArchInstrInfo;
}

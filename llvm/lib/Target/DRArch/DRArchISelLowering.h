#ifndef LLVM_LIB_TARGET_DRARCH_DRARCHISELLOWERING_H
#define LLVM_LIB_TARGET_DRARCH_DRARCHISELLOWERING_H

#include "DRArch.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class DRArchSubtarget;
class DRArchTargetMachine;

namespace DRArchISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace DRArchISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_DRARCH_DRARCHISELLOWERING_H

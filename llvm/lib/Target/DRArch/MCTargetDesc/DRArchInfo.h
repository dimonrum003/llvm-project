#ifndef LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHINFO_H
#define LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace DRArchOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace DRArchOp

} // end namespace llvm

#endif

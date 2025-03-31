#ifndef LLVM_LIB_TARGET_DRArch_DRArch_H
#define LLVM_LIB_TARGET_DRArch_DRArch_H

#include "MCTargetDesc/DRArchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define DRARCH_DUMP(Color)                                                      \
   {                                                                            \
     llvm::errs().changeColor(Color)                                            \
         << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
     llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
   }
 // #define DRARCH_DUMP(Color) {}

#define DRARCH_DUMP_RED     DRARCH_DUMP(llvm::raw_ostream::RED)
#define DRARCH_DUMP_GREEN   DRARCH_DUMP(llvm::raw_ostream::GREEN)
#define DRARCH_DUMP_YELLOW  DRARCH_DUMP(llvm::raw_ostream::YELLOW)
#define DRARCH_DUMP_CYAN    DRARCH_DUMP(llvm::raw_ostream::CYAN)
#define DRARCH_DUMP_MAGENTA DRARCH_DUMP(llvm::raw_ostream::MAGENTA)
#define DRARCH_DUMP_WHITE   DRARCH_DUMP(llvm::raw_ostream::WHITE)

namespace llvm {
class DRArchTargetMachine;
class FunctionPass;

FunctionPass *createDRArchISelDag(DRArchTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_DRArch_DRArch_H

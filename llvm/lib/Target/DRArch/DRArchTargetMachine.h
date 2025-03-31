#ifndef LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H

#include "DRArchSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheDRArchTarget;

class DRArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  DRArchSubtarget Subtarget;

public:
  DRArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                      bool JIT);

  const DRArchSubtarget *getSubtargetImpl(const Function &) const override {
    DRARCH_DUMP_CYAN
    return &Subtarget;
  }
  
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H

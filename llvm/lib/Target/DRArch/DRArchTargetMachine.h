#ifndef LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheDRArchTarget;

class DRArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;

public:
  DRArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                  StringRef FS, const TargetOptions &Options,
                  std::optional<Reloc::Model> RM,
                  std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                  bool JIT);

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H

#ifndef LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"
#include <optional>

namespace llvm {
extern Target TheDRArchTarget;

class DRArchTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
public:
  DRArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                      bool JIT, bool isLittle);

  DRArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                      bool JIT);

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_DRARCH_DRARCHTARGETMACHINE_H

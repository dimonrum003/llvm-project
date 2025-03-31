#include "DRArchTargetMachine.h"
#include "DRArch.h"
#include "TargetInfo/DRArchTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeDRArchTarget() {
  // Register the target.
  DRARCH_DUMP_CYAN
  RegisterTargetMachine<DRArchTargetMachine> A(getTheDRArchTarget());
}

DRArchTargetMachine::DRArchTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  DRARCH_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// DRArch Code Generator Pass Configuration Options.
class DRArchPassConfig : public TargetPassConfig {
public:
  DRArchPassConfig(DRArchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    DRARCH_DUMP_CYAN
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *DRArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  DRARCH_DUMP_CYAN
  return new DRArchPassConfig(*this, PM);
}

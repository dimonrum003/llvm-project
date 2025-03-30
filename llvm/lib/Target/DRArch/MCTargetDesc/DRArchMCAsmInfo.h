#ifndef LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCASMINFO_H
#define LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class DRArchELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit DRArchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCASMINFO_H

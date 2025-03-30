#ifndef LLVM_LIB_TARGET_DRARCH_DRARCHREGISTERINFO_H
#define LLVM_LIB_TARGET_DRARCH_DRARCHREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "DRArchGenRegisterInfo.inc"

namespace llvm {

struct DRArchRegisterInfo : public DRArchGenRegisterInfo {
public:
  DRArchRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_DRARCH_DRARCHREGISTERINFO_H

#ifndef LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCTARGETDESC_H

#include <memory>
namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createDRArchMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createDRArchAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                     const MCRegisterInfo &MRI,
                                     const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createDRArchELFObjectWriter(bool Is64Bit,
                                                                  uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for DRArch registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "DRArchGenRegisterInfo.inc"

// Defines symbolic names for the DRArch instructions.
#define GET_INSTRINFO_ENUM
#include "DRArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_DRARCH_MCTARGETDESC_DRARCHMCTARGETDESC_H

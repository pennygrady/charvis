
#pragma once

#define CONFIG_ARM_HIKEY_OUTSTANDING_PREFETCHERS  0
#define CONFIG_ARM_HIKEY_PREFETCHER_STRIDE  0
#define CONFIG_ARM_HIKEY_PREFETCHER_NPFSTRM  0
/* disabled: CONFIG_ARM_HIKEY_PREFETCHER_STBPFDIS */
/* disabled: CONFIG_ARM_HIKEY_PREFETCHER_STBPFRS */
/* disabled: CONFIG_PLAT_IMX7 */
#define CONFIG_USER_TOP  0xa0000000
/* disabled: CONFIG_ARCH_AARCH32 */
#define CONFIG_ARCH_AARCH64  1  /* KernelSel4ArchAarch64=ON */
/* disabled: CONFIG_ARCH_ARM_HYP */
/* disabled: CONFIG_ARCH_RISCV32 */
/* disabled: CONFIG_ARCH_RISCV64 */
/* disabled: CONFIG_ARCH_X86_64 */
/* disabled: CONFIG_ARCH_IA32 */
#define CONFIG_SEL4_ARCH  aarch64
#define CONFIG_ARCH_ARM  1  /* KernelArchARM=ON */
#define CONFIG_ARCH  arm
#define CONFIG_WORD_SIZE  64
#define CONFIG_ARM_PLAT  tx2
#define CONFIG_MACH  nvidia
/* disabled: CONFIG_PLAT_BCM2711 */
/* disabled: CONFIG_PLAT_BCM2837 */
/* disabled: CONFIG_PLAT_FVP */
/* disabled: CONFIG_PLAT_HIKEY */
/* disabled: CONFIG_PLAT_IMX8MQ_EVK */
/* disabled: CONFIG_PLAT_IMX8MM_EVK */
/* disabled: CONFIG_PLAT_MAAXBOARD */
/* disabled: CONFIG_PLAT_ODROIDC2 */
/* disabled: CONFIG_PLAT_ODROIDC4 */
/* disabled: CONFIG_PLAT_QEMU_ARM_VIRT */
/* disabled: CONFIG_PLAT_ROCKPRO64 */
/* disabled: CONFIG_PLAT_TQMA8XQP1GB */
/* disabled: CONFIG_PLAT_TX1 */
#define CONFIG_PLAT_TX2  1  /* KernelPlatformTx2=ON */
/* disabled: CONFIG_PLAT_ZYNQMP */
#define CONFIG_PLAT  tx2
/* disabled: CONFIG_ARM_CORTEX_A7 */
/* disabled: CONFIG_ARM_CORTEX_A8 */
/* disabled: CONFIG_ARM_CORTEX_A9 */
/* disabled: CONFIG_ARM_CORTEX_A15 */
/* disabled: CONFIG_ARM_CORTEX_A35 */
/* disabled: CONFIG_ARM_CORTEX_A53 */
/* disabled: CONFIG_ARM_CORTEX_A55 */
#define CONFIG_ARM_CORTEX_A57  1  /* KernelArmCortexA57=ON */
/* disabled: CONFIG_ARM_CORTEX_A72 */
/* disabled: CONFIG_ARCH_ARM_V7A */
/* disabled: CONFIG_ARCH_ARM_V7VE */
#define CONFIG_ARCH_ARM_V8A  1  /* KernelArchArmV8a=ON */
#define CONFIG_ARM_SMMU  1  /* KernelArmSMMU=ON */
#define CONFIG_AARCH64_SERROR_IGNORE  1  /* KernelAArch64SErrorIgnore=ON */
#define CONFIG_ARM_MACH  nvidia
#define CONFIG_LIB_SEL4_MUSLC_SYS_CONSTRUCTOR_PRIORITY  201
/* disabled: CONFIG_LIB_USB */
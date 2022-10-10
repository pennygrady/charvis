
#pragma once

#define CONFIG_VM_ONDEMAND_DEVICE_INSTALL  1  /* VmOnDemandDeviceInstall=ON */
/* disabled: CONFIG_VM_EMMC2_NODMA */
/* disabled: CONFIG_VM_VUSB */
#define CONFIG_VM_PCI_SUPPORT  1  /* VmPCISupport=ON */
/* disabled: CONFIG_VM_VIRTIO_NET_ARPING */
/* disabled: CONFIG_VM_VIRTIO_NET_VIRTQUEUE */
/* disabled: CONFIG_VM_VIRTIO_CON */
#define CONFIG_VM_ROOTFS_MMCBLK0P2  1  /* VmRootfsMmcblk0p2=ON */
/* disabled: CONFIG_VM_ROOTFS_MMCBLK1P2 */
#define CONFIG_VM_ROOTFS  mmcblk0p2
#define CONFIG_VM_TK1_INITRD_ROOTFS  1  /* VmTk1InitrdRootfs=ON */
/* disabled: CONFIG_VM_TK1_EMMC_ROOTFS */
#define CONFIG_VM_TK1_ROOTFS  initrd
/* disabled: CONFIG_TK1_DEVICE_FWD */
/* disabled: CONFIG_TK1_INSECURE */
#define CONFIG_VM_INITRD_FILE  1  /* VmInitRdFile=ON */
#define CONFIG_VM_DTB_FILE  1  /* VmDtbFile=ON */
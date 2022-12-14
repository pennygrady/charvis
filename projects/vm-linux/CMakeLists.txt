#
# Copyright 2018, Data61, CSIRO (ABN 41 687 119 230)
#
# SPDX-License-Identifier: BSD-2-Clause
#

cmake_minimum_required(VERSION 3.8.2)

project(camkes-vm-linux C)

include("vm-linux-helpers.cmake")
include("linux-source-helpers.cmake")
include(ExternalProject)

set(configure_string "")

config_option(
    CAmkESVMDefaultBuildrootOverlay
    CAMKES_VM_DEFAULT_BUILDROOT_OVERLAY
    "Enable the building of the default buildroot overlay"
    DEFAULT
    OFF
    DEPENDS
    "KernelArchX86"
)

add_config_library(camkes-vm-linux "${configure_string}")

if(CAmkESVMDefaultBuildrootOverlay)
    include(cross_compiling)
    # Add packages,libs and modules used in the linux vm
    set(binary_dir ${CMAKE_BINARY_DIR}/camkes-linux-artifacts)

    if(KernelSel4ArchX86_64)
      # Get Custom toolchain for 64-bit Linux
      FindCustomPollyToolchain(LINUX_TOOLCHAIN "linux-gcc-64bit-pic")
      set(arch_size_dir "64")
    else()
      # Get Custom toolchain for 32-bit Linux
      FindCustomPollyToolchain(LINUX_TOOLCHAIN "linux-gcc-32bit-pic")
      set(arch_size_dir "32")
    endif()

    # Setup Linux Sources
    GetDefaultLinuxMajor(linux_major)
    GetDefaultLinuxMinor(linux_minor)
    GetDefaultLinuxMd5(linux_md5)
    DownloadLinux(${linux_major} ${linux_minor} ${linux_md5} vm_linux_extract_dir download_vm_linux)
    # Linux config and symvers are to be copied to unpacked archive
    set(
        linux_config
        "${CMAKE_CURRENT_SOURCE_DIR}/linux_configs/${linux_major}.${linux_minor}/${arch_size_dir}/config"
    )
    set(
        linux_symvers
        "${CMAKE_CURRENT_SOURCE_DIR}/linux_configs/${linux_major}.${linux_minor}/${arch_size_dir}/Module.symvers"
    )
    # Configure unpacked archive with config and symvers
    ConfigureLinux(
        ${vm_linux_extract_dir}
        ${linux_config}
        ${linux_symvers}
        configure_vm_linux
        DEPENDS
        download_vm_linux
    )

    # Build camkes connector apps
    set(connector_apps_stamp_dir ${CMAKE_CURRENT_BINARY_DIR}/camkes-connector-apps-stamp)
    set(connector_apps_binary_dir ${binary_dir}/connector-apps)
    ExternalProject_Add(
        camkes-connector-apps
        URL
        file:///${CMAKE_CURRENT_SOURCE_DIR}/camkes-linux-artifacts/camkes-linux-apps/camkes-connector-apps
        BINARY_DIR
        ${connector_apps_binary_dir}
        BUILD_ALWAYS
        ON
        STAMP_DIR
        ${connector_apps_stamp_dir}
        EXCLUDE_FROM_ALL
        INSTALL_COMMAND
        ""
        CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_TOOLCHAIN_FILE=${LINUX_32BIT_TOOLCHAIN}
    )

    # Build camkes connector modules
    set(connector_modules_stamp_dir ${CMAKE_CURRENT_BINARY_DIR}/camkes-connector-modules-stamp)
    set(connector_modules_binary_dir ${binary_dir}/connector-modules)
    ExternalProject_Add(
        camkes-connector-modules
        URL
        file:///${CMAKE_CURRENT_SOURCE_DIR}/camkes-linux-artifacts/camkes-linux-modules/camkes-connector-modules
        BINARY_DIR
        ${connector_modules_binary_dir}
        BUILD_ALWAYS
        ON
        STAMP_DIR
        ${connector_modules_stamp_dir}
        EXCLUDE_FROM_ALL
        INSTALL_COMMAND
        ""
        DEPENDS
        download_vm_linux
        configure_vm_linux
        CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_TOOLCHAIN_FILE=${LINUX_32BIT_TOOLCHAIN}
        -DLINUX_KERNEL_DIR=${vm_linux_extract_dir}
        -DMODULE_HELPERS_FILE=${CMAKE_CURRENT_SOURCE_DIR}/linux-module-helpers.cmake
    )

    # Declare camkes connector apps
    AddExternalProjFilesToOverlay(
        camkes-connector-apps
        ${connector_apps_binary_dir}
        default_buildroot_overlay
        "usr/sbin"
        FILES
        pkgs/consumes_event/consumes_event_wait
        pkgs/emits_event/emits_event_emit
        pkgs/dataport/dataport_read
        pkgs/dataport/dataport_write
        pkgs/string_reverse/string_reverse
    )

    # Declare camkes connector modules
    AddExternalProjFilesToOverlay(
        camkes-connector-modules
        ${connector_modules_binary_dir}
        default_buildroot_overlay
        "lib/modules/4.8.16/kernel/drivers/vmm"
        FILES
        connection.ko
    )

    # Add additional init scripts to the default buildroot overlay
    AddFileToOverlayDir(
        "init"
        ${CMAKE_CURRENT_LIST_DIR}/camkes-linux-artifacts/camkes-linux-init-scripts/buildroot_init/init_template
        "."
        default_buildroot_overlay
    )
endif()

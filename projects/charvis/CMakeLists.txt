#
# Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
#
# SPDX-License-Identifier: BSD-2-Clause
#

cmake_minimum_required(VERSION 3.8.2)
include(settings.cmake)
project(charvis C CXX ASM)

add_subdirectory("root_task/${AppArch}")
add_subdirectory("terminal_task")
add_subdirectory("hypervisor_task")
# Should be done adding targets, can now generate the root server and the global configuration

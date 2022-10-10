#
# Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
#
# SPDX-License-Identifier: BSD-2-Clause
#

cmake_minimum_required(VERSION 3.7.2)

project(terminal_task C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")

file(
    GLOB
        deps
        src/*.c
)

list(SORT deps)

add_library(terminal STATIC EXCLUDE_FROM_ALL ${deps})
target_include_directories(terminal PUBLIC include "include")

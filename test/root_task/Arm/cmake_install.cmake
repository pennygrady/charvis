# Install script for directory: /home/chen/sel4/charvis/projects/charvis/root_task/Arm

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/chen/sel4/charvis/test/kernel/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/root_task/Arm/elfloader/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/root_task/Arm/sel4runtime/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/root_task/Arm/musllibc/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/libsel4/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/root_task/Arm/util_libs/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/root_task/Arm/seL4_libs/cmake_install.cmake")

endif()


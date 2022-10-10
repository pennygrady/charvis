# Install script for directory: /home/chen/sel4/charvis/projects/util_libs

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
  include("/home/chen/sel4/charvis/test/util_libs/libutils/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/libplatsupport/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/libelf/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/libcpio/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/libpci/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/libethdrivers/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/liblwip/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/libpicotcp/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/libfdt/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/util_libs/libsatadrivers/cmake_install.cmake")

endif()


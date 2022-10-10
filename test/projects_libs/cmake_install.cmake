# Install script for directory: /home/chen/sel4/charvis/projects/projects_libs

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
  include("/home/chen/sel4/charvis/test/projects_libs/libjansson/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libmsgpack/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libringbuffer/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libsdhcdrivers/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libusbdrivers/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libnfs/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libvirtqueue/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libvswitch/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libfdtgen/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libtx2bpmp/cmake_install.cmake")
  include("/home/chen/sel4/charvis/test/projects_libs/libplatsupportports/cmake_install.cmake")

endif()


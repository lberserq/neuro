# Install script for directory: /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "./build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/libdicomsdl.a")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/ext/opj/cmake_install.cmake")
  include("/home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/ext/ijg/cmake_install.cmake")
  include("/home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/ext/zlib/cmake_install.cmake")
  include("/home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/ext/minizip/cmake_install.cmake")
  include("/home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/ext/expat/cmake_install.cmake")
  include("/home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/lib/cmake_install.cmake")
  include("/home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example/cmake_install.cmake")

endif()


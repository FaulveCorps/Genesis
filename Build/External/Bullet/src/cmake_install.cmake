# Install script for directory: C:/Users/jpfau/Desktop/Genesis/Genesis/External/Bullet/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/GenesisEngine")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/Bullet3OpenCL/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/Bullet3Serialize/Bullet2FileLoader/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/Bullet3Dynamics/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/Bullet3Collision/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/Bullet3Geometry/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/BulletInverseDynamics/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/BulletSoftBody/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/BulletCollision/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/BulletDynamics/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/LinearMath/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/Bullet3Common/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/src/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()

# Install script for directory: C:/Users/jpfau/Desktop/Genesis/Genesis/External/Bullet/examples

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
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/HelloWorld/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/BasicDemo/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/ExampleBrowser/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/RobotSimulator/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/SharedMemory/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/ThirdPartyLibs/Gwen/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/ThirdPartyLibs/BussIK/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/ThirdPartyLibs/clsocket/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/OpenGLWindow/cmake_install.cmake")
  include("C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/TwoJoint/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/jpfau/Desktop/Genesis/Genesis/Build/External/Bullet/examples/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()

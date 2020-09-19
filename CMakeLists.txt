cmake_minimum_required(VERSION 3.0.0)
project(multithreadInCpp VERSION 0.1.0)

INCLUDE_DIRECTORIES(
    include
    )

AUX_SOURCE_DIRECTORY(src DIR_SRCS)
SET(TEST_MATH
${DIR_SRCS}
 )

include(CTest)
enable_testing()

SET(CMAKE_BUILD_TYPE "Debug")  
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")  
set(CMAKE_CXX_FLAGS   "-pthread")                    

add_executable(${PROJECT_NAME} ${TEST_MATH})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

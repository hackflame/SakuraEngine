cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(CGD 
VERSION 1.00
LANGUAGES CXX
)

add_subdirectory(CGD_Vulkan)
add_subdirectory(CGD_Direct3D12)
add_subdirectory(CGD)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GraphicsCommon)

add_library(CGDModule SHARED CGDModule.h CGDModule.cpp)
target_link_libraries(CGDModule SPA CGD)
  
message(STATUS "Graphicsinterface Root: ${CMAKE_CURRENT_SOURCE_DIR}")
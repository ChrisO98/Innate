cmake_minimum_required(VERSION 3.24)
project(InnateEngine)

# Force x64 for MSVC multi-config generators
#if(NOT CMAKE_GENERATOR_PLATFORM)
#    set(CMAKE_GENERATOR_PLATFORM x64 CACHE INTERNAL "" FORCE)
#endif()

# C++/C standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Custom option for build behavior
option(PRODUCTION_BUILD "Make this a production build" OFF)

# Global output directories
set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/bin)
#set(INT_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/bin-int) # defines variable INT_OUTPUT_DIR and sets it to "${CMAKE_SOURCE_DIR}/bin-int"

# Subprojects
add_subdirectory(Innate)
add_subdirectory(Sandbox)

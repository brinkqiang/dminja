cmake_minimum_required(VERSION 3.21)

PROJECT(dminja)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

ADD_DEFINITIONS(-DCATCH_CONFIG_MAIN)


InterfaceImport("dminja" "include" "")
if(PROJECT_IS_TOP_LEVEL)
    ExeImport("test" "dminja")
endif()

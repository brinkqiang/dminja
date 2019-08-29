cmake_minimum_required(VERSION 3.2)

PROJECT(dminja)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(DMINJA_VERSION_MAJOR "1")
SET(DMINJA_VERSION_MINOR "0")
SET(DMINJA_VERSION_PATCH "1")
SET(DMINJA_VERSION "${DMINJA_VERSION_MAJOR}.${DMINJA_VERSION_MINOR}.${DMINJA_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMINJA_VERSION}")

OPTION(USE_DMINJA "use dminja" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dminja_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dminja_config.h)

ModuleImport("dmlog" "thirdparty/dmlog")
LibImport("dminja" "src/dminja_module")
ExeImport("test" "dminja;dmlog")

#ADD_CUSTOM_COMMAND(
#TARGET dminjatest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dminjatest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dminja
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMINJA_LIBS "dminja")
#MARK_AS_ADVANCED(${DMINJA_LIBS})
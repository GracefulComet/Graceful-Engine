cmake_minimum_required (VERSION 2.6) 

PROJECT( GracefulEngine )

include_directories("/usr/local/include/")
#include_directories("./include")
SET ( GracefulEngine_VERSION_MAJOR A )
SET ( GracefulEngine_VERSION_MINOR 0 )
#SET ( LIBRARY_OUTPUT_PATH "./libs"  )
set (CMAKE_CXX_FLAGS "-I/usr/local/include/SDL2 -D_REENTRANT -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL2 -lSDL2_image -g -std=c++11")
#set (CMAKE_CXX_LINKER_FLAGS "-lSDL2 -lSDL2_image")
file(GLOB SRCS *.cpp , *.h)
ADD_EXECUTABLE( GEtidy ${SRCS} )

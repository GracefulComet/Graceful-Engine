cmake_minimum_required (VERSION 2.6) 

PROJECT( GracefulEngine )

include_directories("/usr/local/include/")
include_directories("./include")
SET ( GracefulEngine_VERSION_MAJOR A )
SET ( GracefulEngine_VERSION_MINOR 0 )
SET ( CMAKE_EXPORT_COMPILE_COMMANDS=ON)
#SET ( LIBRARY_OUTPUT_PATH "./libs"  )

if (UNIX)
	set (CMAKE_CXX_FLAGS "-I/usr/local/include/SDL2 -D_REENTRANT -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL2 -lSDL2_image -g -std=c++11")
endif (UNIX)

if (WIN32)

	set (CMAKE_CXX_FLAGS "-I./include/SDL2 -D_REENTRANT -L./lib -Wl,-rpath,./lib -lSDL2 -lSDL2_image -g -std=c++11")

endif (WIN32)

#set (CMAKE_CXX_LINKER_FLAGS "-lSDL2 -lSDL2_image")
file(GLOB SRCS *.cpp , *.h)
ADD_EXECUTABLE( GEtidy ${SRCS} )


cmake_minimum_required(VERSION 2.8)

#SET(CMAKE_CXX_COMPILER /usr/bin/c++)

set(target texture_synthesis)
project( ${target})
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories(${CMAKE_SOURCE_DIR}/include/)
add_executable( ${target}
		${CMAKE_SOURCE_DIR}/include/${target}/texture_synthesis.h
		${CMAKE_SOURCE_DIR}/src/texture_synthesis.cpp
		${CMAKE_SOURCE_DIR}/app/texture_synthesis_app.cpp )
target_link_libraries( ${target} ${OpenCV_LIBS} )


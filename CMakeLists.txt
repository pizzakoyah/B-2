cmake_minimum_required(VERSION 3.7)

project(B-2)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(B-2 ${PROJECT_SOURCE_DIR}/ManyFormat.cpp)
target_link_libraries(B-2 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
IF(MINGW)
	target_link_libraries(B-2 -static-libgcc -static-libstdc++)
ENDIF(MINGW)

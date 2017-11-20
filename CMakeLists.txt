cmake_minimum_required(VERSION 3.9)

project(B-2)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})

#add_executable(ManyFormat ${PROJECT_SOURCE_DIR}/<SOURCE GOES HERE>)
#target_link_libraries(ManyFormat -static-libgcc -static-libstdc++)
#target_link_libraries(ManyFormat ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

cmake_minimum_required(VERSION 3.0.0)
project(secret-service VERSION 0.1.0 LANGUAGES C CXX)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(secret-service ${SOURCES})

target_link_libraries(secret-service SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)as
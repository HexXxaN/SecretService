cmake_minimum_required(VERSION 3.0.0)
project(secret-service VERSION 0.1.0 LANGUAGES C CXX)

add_executable(secret-service src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
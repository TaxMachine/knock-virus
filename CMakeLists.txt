cmake_minimum_required(VERSION 3.28)
project(knock_virus)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES "src/**")

add_executable(knock_virus ${SOURCES})

target_sources(knock_virus PRIVATE ${CMAKE_SOURCE_DIR}/knock_virus.rc)

target_link_libraries(knock_virus PRIVATE Winmm)
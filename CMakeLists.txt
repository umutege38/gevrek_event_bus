cmake_minimum_required(VERSION 3.20)
project(GevrekEventBus LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(GevrekEventBus STATIC
    src/gevrek_event_bus.c
    include/gevrek_event_bus.h)

target_include_directories(GevrekEventBus PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
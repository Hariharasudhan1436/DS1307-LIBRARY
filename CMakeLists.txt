cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(ds1307_project)

pico_sdk_init()

add_executable(ds1307
    main.cpp
    ds1307.cpp
)

target_link_libraries(ds1307 pico_stdlib hardware_i2c)

pico_add_extra_outputs(ds1307)

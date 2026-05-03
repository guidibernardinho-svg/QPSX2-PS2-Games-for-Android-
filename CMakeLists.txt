cmake_minimum_required(VERSION 3.10)

project(QPSX2)

add_library(qpsx2 SHARED native.cpp vulkan_renderer.cpp)

find_library(log-lib log)
find_library(vulkan-lib vulkan)

target_link_libraries(qpsx2 ${log-lib} ${vulkan-lib})

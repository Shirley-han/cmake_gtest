# https://gitee.com/han_jin_fei/lycium/blob/master/doc/cmake_specification.md
cmake_minimum_required(VERSION 3.16.3)
project(main)

add_subdirectory(hello)
add_subdirectory(world)

add_executable(hw main.cpp)

target_include_directories(hw PUBLIC world)
target_include_directories(hw PUBLIC hello)

target_link_libraries(hw PUBLIC helloso)
target_link_libraries(hw PUBLIC worldso)

# build gtest
add_executable(testhello testhello.cpp)
target_include_directories(testhello PUBLIC hello)
target_include_directories(testhello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thrid_party/googletest-1.13.0/install/include)

target_link_libraries(testhello PUBLIC helloso)
target_link_directories(testhello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thrid_party/googletest-1.13.0/install/lib)
target_link_libraries(testhello PUBLIC gtest gtest_main)
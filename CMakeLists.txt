cmake_minimum_required(VERSION 3.31)
project(Katas LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

set(GTEST_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/googletest")
if (EXISTS "${GTEST_SOURCE_DIR}/CMakeLists.txt")
    add_subdirectory("${GTEST_SOURCE_DIR}" "external/googletest" EXCLUDE_FROM_ALL)
    if (TARGET gtest AND NOT TARGET GTest::gtest)
        add_library(GTest::gtest ALIAS gtest)
    endif ()
    if (TARGET gtest_main AND NOT TARGET GTest::gtest_main)
        add_library(GTest::gtest_main ALIAS gtest_main)
    endif ()
else ()
    find_package(GTest REQUIRED)
endif ()



add_executable(Katas_tests
	reverse_linked_list.cpp
)

target_link_libraries(Katas_tests gtest gtest_main)
cmake_minimum_required(VERSION 3.19)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(BUILD_TZ_LIB ON)

project(sqlite-fill)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/extern/date)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/extern/sqlite_orm)

add_executable(sqlite-fill)
target_include_directories(sqlite-fill PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/3rd_party)
target_sources(sqlite-fill PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(sqlite-fill PRIVATE sqlite_orm::sqlite_orm date::date date::date-tz)

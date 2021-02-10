cmake_minimum_required(VERSION 3.7)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)

project(cxx-sqlite-sd)

set(BUILD_TZ_LIB ON)

add_subdirectory(deps)

add_executable(cxx-sqlite-sd)
target_sources(cxx-sqlite-sd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(cxx-sqlite-sd PRIVATE sqlite_orm::sqlite_orm)
target_link_libraries(cxx-sqlite-sd PRIVATE date::date)
target_link_libraries(cxx-sqlite-sd PRIVATE date::date-tz)

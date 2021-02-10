cmake_minimum_required(VERSION 3.19)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)

project(sqlite-fill)

set(BUILD_TZ_LIB ON)

add_subdirectory(deps)

add_executable(sqlite-fill)
target_sources(sqlite-fill PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(sqlite-fill PRIVATE sqlite_orm::sqlite_orm)
target_link_libraries(sqlite-fill PRIVATE date::date)
target_link_libraries(sqlite-fill PRIVATE date::date-tz)

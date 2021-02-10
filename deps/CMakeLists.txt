include(FetchContent)

FetchContent_Declare(sqliteOrm
  GIT_REPOSITORY https://github.com/fnc12/sqlite_orm
  GIT_TAG        origin/dev
)
FetchContent_MakeAvailable(sqliteOrm)

FetchContent_Declare(date
  GIT_REPOSITORY https://github.com/HowardHinnant/date.git
  GIT_TAG        origin/master
)
FetchContent_MakeAvailable(date)
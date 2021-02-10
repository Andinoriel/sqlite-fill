#include <algorithm>
#include <chrono>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include <sqlite_orm/sqlite_orm.h>

#include "datetime.h"

using namespace sqlite_orm;
using namespace datetime;
using namespace std;

struct call {
  int id;
  string date;
  string phone_number;
  int talk_time;
  string status;
};

int main(void) {
  ios::sync_with_stdio(false);

  try {
    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    auto storage = make_storage(
        "db.sqlite",
        make_table("calls",
                   make_column("id", &call::id, autoincrement(), primary_key()),
                   make_column("date", &call::date),
                   make_column("phone_number", &call::phone_number),
                   make_column("talk_time", &call::talk_time),
                   make_column("status", &call::status)));

    storage.sync_schema();

    auto start_date =
        DateTime<>::strptime("20-06-01 00:00:00", "%y-%m-%d %H:%M:%S");
    auto day_count = 14;
    auto time_count = 24;

    vector<DateTime<>> days;
    vector<DateTime<>> hours;
    vector<DateTime<>> minutes;

    // O(n)
    for (size_t n = 0; n < day_count; ++n) {
      days.push_back(start_date + TimeDelta(date::days(n)));
    }
    // O(n^2)
    for (auto &&elem : days) {
      for (size_t n = 0; n < time_count; ++n) {
        hours.push_back(elem + TimeDelta(chrono::hours(n)));
      }
    }
    // O(n^2) + O(n^2)
    for (auto &&elem : hours) {
      for (size_t n = 0; n < 60; ++n) {
        minutes.push_back(elem + TimeDelta(chrono::minutes(n)));
      }
    }

    // O(n^2) + O(n^2)
    std::sort(minutes.begin(), minutes.end());

    // total = O(n) + O(n^2) + O(n^2) + O(n^2) + O(n^2) + O(n^2)
    // total = O(n) + 5*O(n^2)

    for (auto &&elem : minutes) {
      storage.insert(call{-1, elem.strftime("%Y-%m-%d %H:%M:%S"), "0000000000",
                          100, "done"});
    }
    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    std::cout
        << "Elapsed time = "
        << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count()
        << " sec" << std::endl;

  } catch (exception const &ex) {
    std::cout << ex.what() << "\n";
  }
  return 0;
}
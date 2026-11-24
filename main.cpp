#include <iostream>
#include <sqlite3.h>

using namespace std;
int main() {
  sqlite3 *db = nullptr;
  int rc = sqlite3_open("gameroom.db", &db);
  if (rc != SQLITE_OK) {
    cerr << "Open error: " << sqlite3_errmsg(db) << endl;
    sqlite3_close(db);
    return 1;
  }

  const char *sql = R"(
CREATE TABLE IF NOT EXISTS rooms(
id INTEGER PRIMARY KEY AUTOINCREMENT,
room_name VARCHAR(20) NOT NULL,
max_players INTEGER NOT NULL,
owner_id INTEGER NOT NULL
);
)";

  char *errMsg = nullptr;
  rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
  if (rc != SQLITE_OK) {
    cerr << "SQL error: " << errMsg << endl;
    sqlite3_free(errMsg);
  } else {
    cout << "テーブルの作成成功" << endl;
  }

  sqlite3_close(db);
  return 0;
}

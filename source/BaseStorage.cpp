#include "BaseStorage.h"

size_t BaseStorage::open_connection(const std::string& db_name, sqlite3*& connection) {
  ssize_t response = sqlite3_open(db_name.data(), &connection);
  return RC_OK;
}

size_t BaseStorage::close_connection(sqlite3*& connection) {
  ssize_t response = sqlite3_close(connection);
  return RC_OK;
}

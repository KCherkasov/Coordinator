#ifndef BASE_STORAGE_H
#define BASE_STORAGE_H

#include "Miscellaneous.h"
#include "SQLite/sqlite3.h"

class BaseStorage {
  public:
    BaseStorage() {}
    virtual ~BaseStorage() {}
    virtual size_t fill_storage(const std::string& db_name) = 0;
    virtual size_t clear_storage() = 0;
  protected:
    size_t open_connection(const std::string& db_name, sqlite3*& connection);
    size_t close_connection(sqlite3*& connection);
};

#endif

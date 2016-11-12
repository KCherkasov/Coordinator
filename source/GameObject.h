#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <vector>

#include "Miscellaneous.h"
#include "StorageEntities.h"
#include "TextStorage.h"

class GameObject {
  public:
    GameObject(const size_t& own_id = SIZE_T_DEFAULT_VALUE);
    virtual ~GameObject() { _dictionary = NULL; }
    size_t get_own_id() const { return _own_id; }
    TextStorage* get_dictionary() const { return _dictionary; }
    size_t get_name(std::string& result) const;
    size_t get_description(std::string& result) const;
    size_t set_own_id(const size_t& value);
    size_t set_dictionary(TextStorage* value);
    size_t set_name(const std::string& value);
    size_t set_description(const std::string& value);
    virtual size_t what(std::string& result) const  { return RC_OK; }
    virtual size_t short_what(std::string& result) const { return RC_OK; }
    virtual size_t update() = 0;
  protected:
    size_t _own_id;
    TextStorage* _dictionary;
    std::string _name;
    std::string _description;
};

#endif

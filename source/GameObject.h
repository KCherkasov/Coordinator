#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <vector>

#include "Miscellaneous.h"
#include "Messages.h"

class GameObject {
  public:
    GameObject(const size_t& own_id = SIZE_T_DEFAULT_VALUE);
    virtual ~GameObject() {}
    size_t get_own_id() { return _own_id; }
    size_t get_name(std::string& result);
    size_t get_description(std::string& result);
    size_t set_own_id(const size_t& value);
    size_t set_name(const std::string& value);
    size_t set_description(const std::string& value);
    virtual size_t what(std::string& result) = 0;
    virtual size_t update() = 0;
    size_t add_observer(Observer* new_observer);
    size_t remove_observer(Observer* observer);
  protected:
    virtual size_t notify(Message* msg) = 0;
    size_t _own_id;
    Observer* _head;
    std::string _name;
    std::string _description;
};

#endif

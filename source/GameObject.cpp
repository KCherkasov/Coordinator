#include "GameObject.h"

GameObject::GameObject(const size_t& own_id): _own_id(own_id) {
  _name.clear();
  _description.clear();
}

size_t GameObject::get_name(std::string& result) {
  result.clear();
  result = _name;
  if (!result.empty()) {
    return RC_OK;
  } else {
    return RC_EMPTY_STRING;
  }
}

size_t GameObject::get_description(std::string& result) {
  result.clear();
  result = _description;
  if (!result.empty()) {
    return RC_OK;
  } else {
    return RC_EMPTY_STRING;
  }
}

size_t GameObject::set_own_id(const size_t& value) {
  _own_id = value;
  return RC_OK;
}

size_t GameObject::set_name(const std::string& value) {
  if (!value.empty()) {
    _name.clear();
    _name = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

size_t GameObject::set_description(const std::string& value) {
  if (!value.empty()) {
    _description.clear();
    _description = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}


#include "GameObject.h"

GameObject::GameObject(const size_t& own_id): _own_id(own_id), _head(NULL) {
  _name.clear();
  _description.clear();
}

GameObject::~GameObject() {
  Message* last_breath = new OnDieMessage(this);
  notify(last_breath);
  delete last_breath;
  _head = NULL;
}

size_t GameObject::notify(Message*& msg) {
  if (_head == NULL) {
    return RC_NO_OBSERVERS;
  }
  if (msg == NULL) {
    return RC_BAD_INPUT;
  }
  Observer* observer = _head;
  while (observer != NULL) {
    observer->on_notify(msg);
    observer = observer->_next;
  }
  return RC_OK;
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

size_t GameObject::add_observer(Observer* new_observer) {
  if (new_observer != NULL) {
    new_observer->_next = _head;
    _head = new_observer;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

size_t GameObject::remove_observer(Observer* observer) {
  if (observer == NULL) {
    return RC_OK;
  }
  if (_head == observer) {
    _head = observer->_next;
    _observer->_next = NULL;
    return RC_OK;
  }
  Observer* current = _head;
  while (current != NULL) {
    if (current->_next == observer) {
      current->_next = observer->_next;
      observer->_next = NULL;
      return RC_OK;
    }
    current = current->_next;
  }
  return RC_NOT_FOUND;
}

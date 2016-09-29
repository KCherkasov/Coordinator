#include "Subject.h"

Subject::~Subject() {
  _head = NULL;
}

size_t Subject::notify(Message* msg) {
  if (msg == NULL) {
    return RC_BAD_INPUT;
  }
  Observing* observer = _head;
  while (observer != NULL) {
    observer->_observer->on_notify(msg);
    observer = observer->_next;
  }
  return RC_OK;
}

size_t Subject::add_observer(Observer* observer) {
  if (observer == NULL) {
    return RC_BAD_INPUT;
  }
  Observing* to_add = new Observing(_head, observer);
  _head = to_add;
  return RC_OK;
}

size_t Subject::remove_observer(Observer* observer) {
  if (observer == NULL) {
    return RC_OK;
  }
  if (_head->_observer == observer) {
    Observing* buffer = _head;
    _head = _head->_next;
    delete buffer;
    return RC_OK;
  }
  Observing* current = _head;
  while (current->_next != NULL) {
    if (current->_next->_observer == observer) {
      Observing* buffer = current;
      current->_next = current->_next->_next;
      delete current;
      return RC_OK;
    }
    current = current->_next;
  }
  return RC_NOT_FOUND;
}


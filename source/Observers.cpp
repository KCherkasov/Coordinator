#include "Observers.h"

Observer::~Observer() {
  Observable* observable = _observables;
  while (observable != NULL) {
    observable->_observable->remove_observer(this);
    Observable* current = observable;
    observable = observable->_next;
    delete current;
  }
}

size_t Observer::on_die(Message*& msg) {
  if (typeid(*msg) == typeid(OnDieMessage)) {
    OnDieMessage* on_die = dynamic_cast<OnDieMessage*>(msg);
    remove_observable(on_die->_sender);
    return OR_OK;
  }
  return OR_NOT_PROCESSED;
}

size_t Observer::add_observable(GameObject*& observable) {
  if (observable == NULL) {
    return RC_BAD_INPUT;
  }
  Observable* to_add = new Observable(observable);
  to_add->_next = _observables;
  _observables = to_add;
  return RC_OK;
}

size_t Observer::remove_observable(Observable* observable) {
  if (observable == NULL) {
    return RC_OK;
  }
  if (observable == _observables) {
    _observables = observable->_next;
    observable->_next = NULL;
    return RC_OK;
  }
  Observable* current = _observables;
  while (current != NULL) {
    if (current->_next == observable) {
      current->_next = observable->_next;
      observable->_next = NULL;
      return RC_OK;
    }
    current = current->_next;
  }
  return RC_NOT_FOUND;
}


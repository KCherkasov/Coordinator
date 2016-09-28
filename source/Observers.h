#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

#include "GameObject.h"
#include "Miscellaneous.h"
#include "Messages.h"

enum ObserverResponses { OR_OK, OR_NOT_PROCESSED, OR_SIZE };

class Observer {
  public:
    Observer(): _next(NULL), _observables(NULL) {}
    virtual ~Observer();
    virtual size_t on_notify(Message*& msg) = 0;
    size_t add_observable(GameObject* observable);
    size_t remove_observable(Observable* observable);
  protected:
    size_t on_die(Message*& msg);
    Observer* _next;
    Observable* _observables;
};

class Observable {
  public:
    friend class Observer;
    Observable(GameObject* observable): _observable(observable), _next(NULL) {}
    ~Observable() { _observable = NULL; _next = NULL; }
  protected:
    GameObject* _observable;
    Observable* _next;
};

#endif

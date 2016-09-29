#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

#include "Messages.h"

enum ObserverResponses { OR_OK, OR_NOT_PROCESSED, OR_SIZE };

class Observer {
  public:
    Observer() {}
    virtual ~Observer() {};
    virtual size_t on_notify(Message* msg) = 0;
};

struct Observing {
  Observing(Observing* next = NULL, Observer* observer = NULL): _next(next), _observer(observer) {}
  ~Observing() { _next = NULL; _observer = NULL; }
  Observing* _next;
  Observer* _observer;
};

#endif

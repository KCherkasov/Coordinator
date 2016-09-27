#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Miscellaneous.h"
#include "Messages.h"

class Observer {
  public:
    Observer(): _next(NULL) {}
    virtual ~Observer() {}
    virtual on_notify(Message* msg) = 0;
  protected:
    Observer* _next;
};

#endif

#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>
#include <vector>

#include "GameObject.h"
#include "Miscellaneous.h"

class Message {
  public:
    Message() {}
    virtual ~Message() {}
};

class OnDieMessage: public Message {
  public: 
    OnDieMessage(GameObject* sender): Message() { _sender = sender; }
    virtual ~OnDieMessage() { _sender = NULL; }
    GameObject* _sender;
};

#endif

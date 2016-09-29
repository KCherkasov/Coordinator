#ifndef GAME_MESSAGES_H
#define GAME_MESSAGES_H

#include <string>
#include <vector>

#include "GameObject.h"

class Message {
  public:
    Message(GameObject* sender = NULL): _sender(sender) {}
    virtual ~Message() { _sender = NULL; }
    GameObject* sender() { return _sender; }
  protected:
    GameObject* _sender;
};

#endif

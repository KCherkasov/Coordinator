#ifndef SUBJECT_H
#define SUBJECT_H

#include "Messages.h"
#include "Observers.h"
#include "Miscellaneous.h"

class Subject {
  public:
    Subject(): _head(NULL) {}
    ~Subject();
    size_t update(Message* msg);
    size_t add_observer(Observer* observer);
    size_t remove_observer(Observer* observer);
  protected:
    Observing* _head;

    size_t notify(Message* msg);
};

struct SubjectNode {
  SubjectNode* _next;
  Subject* _subject;
  SubjectNode(SubjectNode* next = NULL, Subject* subject = NULL): _next(next), _subject(subject) {}
  ~SubjectNode() { _next = NULL; _subject = NULL; }
};

#endif

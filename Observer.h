#ifndef OBSERVER_H
#define OBSERVER_H
#include "Subject.h"

class Observer{
public:
    virtual ~Observer();
    virtual void update(Subject* s) = 0;
    virtual void subscribe(Subject* s) = 0;
    virtual void unsubscribe(Subject* s) = 0;
};

#endif // OBSERVER_H

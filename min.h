#ifndef MIN_H
#define MIN_H
#include "Observer.h"
#include "Function.h"
#include <list>
class Cell;

class Min : public Observer, public Function
{
public:
    Min(){}
    virtual ~Min(){}
    void update() override;
    void subscribe(Subject *s) override;
    void unsubscribe(Subject *s) override;
    float compute() override;
};

#endif // MIN_H

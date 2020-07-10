#ifndef SUM_H
#define SUM_H
#include "Observer.h"
#include "Function.h"
#include <list>
class Cell;

class Sum : public Observer, public Function
{
public:
    Sum(){}
    virtual ~Sum(){}
    void update() override;
    void subscribe(Subject *s) override;
    void unsubscribe(Subject *s) override;
    float compute() override;
private:
    std::list<Cell*> subjects;
    float sumValue;
};

#endif // SUM_H

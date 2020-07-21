#ifndef MAX_H
#define MAX_H
#include "Observer.h"
#include "Function.h"
#include <list>
class Cell;

class Max : public Observer,public Function
{
public:
    Max(){}
    virtual ~Max(){}
    void update() override;
    void subscribe(Subject *s) override;
    void unsubscribe(Subject *s) override;
    float compute() override;
};

#endif // MAX_H

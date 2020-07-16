#ifndef MEAN_H
#define MEAN_H
#include "Observer.h"
#include "Function.h"
#include <list>
class Cell;

class Mean : public Observer, public Function
{
public:
    Mean(){}
    virtual ~Mean(){}
    void update() override;
    void subscribe(Subject *s) override;
    void unsubscribe(Subject *s) override;
    float compute() override;
    float getMeanValue() const;
private:
    float meanValue;
};

#endif // MEAN_H

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
    float getSumValue() const;
    Cell* getLastCellFound() const;
    bool findCell(int row,int column);
private:
    std::list<Cell*> subjects;
    float sumValue;
    Cell* lastCellFound;
};

#endif // SUM_H

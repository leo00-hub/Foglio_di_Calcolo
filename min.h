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
    float getMinValue() const;
    Cell* getLastCellFound() const;
    bool findCell(int row,int column);
private:
    std::list<Cell*> subjects;
    float minValue;
    Cell* lastCellFound;
};

#endif // MIN_H

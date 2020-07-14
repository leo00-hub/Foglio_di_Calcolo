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
    Cell* getLastCellFound() const;
    float findCell(int row,int column);
private:
    std::list<Cell*> subjects;
    float meanValue;
    Cell* lastCellFound;
};

#endif // MEAN_H

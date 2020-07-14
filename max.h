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
    float getMaxValue() const;
    Cell* getLastCellFound() const;
    bool findCell(int row,int column);
private:
    std::list<Cell*> subjects;
    float maxValue;
    Cell* lastCellFound;

};

#endif // MAX_H

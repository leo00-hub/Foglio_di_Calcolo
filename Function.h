#ifndef FUNCTION_H
#define FUNCTION_H
#include <list>
class Cell;


class Function{
public:
    virtual ~Function(){}
    virtual float compute() = 0;
    virtual bool findCell(int row,int column);
    Cell* getLastCellFound() const;
protected:
    std::list<Cell*> subjects;
    Cell* lastCellFound;
};

#endif // FUNCTION_H

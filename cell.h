#ifndef CELL_H
#define CELL_H
#include "Subject.h"
#include "sum.h"
#include "mean.h"
#include "max.h"
#include "min.h"

class Cell : public Subject
{
public:
    Cell(Sum* s,Mean* me,Max* ma,Min* mi,int r = 0,int c = 0,float v = 0);
    virtual ~Cell();
    void attach() override;
    void detach() override;
    void notify() override;
    float getValue() const;
    void setValue(float v);
    int getRow() const;
    int getColumn() const;

private:
    Sum* sumFunction;
    Mean* meanFunction;
    Max* maxFunction;
    Min* minFunction;
    int row;
    int column;
    float value;
};

#endif // CELL_H

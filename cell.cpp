#include "cell.h"

Cell::Cell(Sum* s,Mean* me,Max* ma,Min* mi,int r,int c,float v) : sumFunction(s),meanFunction(me),maxFunction(ma),minFunction(mi),row(r),column(c),value(v){
    attach();
}

Cell::~Cell(){
    detach();
}

void Cell::attach()
{
    if(sumFunction)
        sumFunction->subscribe(this);
    if(meanFunction)
        meanFunction->subscribe(this);
    if(maxFunction)
        maxFunction->subscribe(this);
    if(minFunction)
        minFunction->subscribe(this);
    notify();
}

void Cell::detach()
{
    if(sumFunction)
        sumFunction->unsubscribe(this);
    if(meanFunction)
        meanFunction->unsubscribe(this);
    if(maxFunction)
        maxFunction->unsubscribe(this);
    if(minFunction)
        minFunction->unsubscribe(this);
    notify();
}

void Cell::notify()
{
    if(sumFunction)
        sumFunction->update();
    if(meanFunction)
        meanFunction->update();
    if(maxFunction)
        maxFunction->update();
    if(minFunction)
        minFunction->update();
}

float Cell::getValue() const
{
    return value;
}

void Cell::setValue(float v)
{
    value = v;
    notify();
}

int Cell::getRow() const
{
    return row;
}

int Cell::getColumn() const
{
    return column;
}

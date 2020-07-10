#include "cell.h"

Cell::Cell(Sum* s,Mean* me,Max* ma,Min* mi) : sumFunction(s),meanFunction(me),maxFunction(ma),minFunction(mi){
    attach();
}

Cell::~Cell(){
    detach();
}

void Cell::attach()
{
    if(sumFunction!= nullptr)
        sumFunction->subscribe(this);
    if(meanFunction!=nullptr)
        meanFunction->subscribe(this);
    if(maxFunction!=nullptr)
        maxFunction->subscribe(this);
    if(minFunction!=nullptr)
        minFunction->subscribe(this);
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

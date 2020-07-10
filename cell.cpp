#include "cell.h"

Cell::Cell(Sum* s,Mean* me,Max* ma,Min* mi) : sumFunction(s),meanFunction(me),maxFunction(ma),minFunction(mi){
    attach();
}

Cell::~Cell(){
    detach();
}

void Cell::attach()
{
    sumFunction->subscribe(this);
    meanFunction->subscribe(this);
    maxFunction->subscribe(this);
    minFunction->subscribe(this);
}

void Cell::detach()
{
   sumFunction->unsubscribe(this);
   meanFunction->unsubscribe(this);
   maxFunction->unsubscribe(this);
   minFunction->unsubscribe(this);
}

void Cell::notify()
{
    sumFunction->update();
    meanFunction->update();
    maxFunction->update();
    minFunction->update();
}

float Cell::getValue() const
{
   return value;
}

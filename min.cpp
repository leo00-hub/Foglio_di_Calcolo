#include "min.h"
#include "cell.h"


void Min::update()
{
   minValue = compute();
}

void Min::subscribe(Subject *s)
{
    auto c = static_cast<Cell*>(s);
    subjects.push_back(c);
}

void Min::unsubscribe(Subject *s)
{
    auto c = static_cast<Cell*>(s);
    subjects.remove(c);
}

float Min::compute()
{
    float min = (*(subjects.begin()))->getValue();
    for(auto it : subjects){
        if(it->getValue() < min)
            min = it->getValue();
    }
    return min;
}

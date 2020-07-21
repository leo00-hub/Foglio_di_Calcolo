#include "mean.h"
#include "cell.h"


void Mean::update()
{
    value = compute();
}

void Mean::subscribe(Subject *s)
{
   auto c = static_cast<Cell*>(s);
   subjects.push_back(c);
}

void Mean::unsubscribe(Subject *s)
{
   auto c = static_cast<Cell*>(s);
   subjects.remove(c);
}

float Mean::compute()
{
    float mean = 0;
    int count = 0;
    for(auto it : subjects){
        mean += it->getValue();
        count++;
    }
    mean /= count;
    return mean;
}

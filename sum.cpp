#include "sum.h"
#include "cell.h"


void Sum::update()
{
    sumValue = compute();
}

void Sum::subscribe(Subject *s)
{
    auto c = static_cast<Cell*>(s);
    subjects.push_back(c);
}

void Sum::unsubscribe(Subject *s)
{
    auto c = static_cast<Cell*>(s);
    subjects.remove(c);
}

float Sum::compute()
{
    float sum = 0;
    for(auto it : subjects)
        sum += it->getValue();
    return sum;
}

#include "max.h"
#include "cell.h"



void Max::update()
{
    maxValue = compute();
}

void Max::subscribe(Subject *s)
{
    auto c = static_cast<Cell*>(s);
    subjects.push_back(c);
}

void Max::unsubscribe(Subject *s)
{
    auto c = static_cast<Cell*>(s);
    subjects.remove(c);
}

float Max::compute()
{
    float max;
    if(subjects.size() != 0){
        max = (*(subjects.begin()))->getValue();
        for(auto it : subjects){
            if(it->getValue() > max)
                max = it->getValue();
        }
    }
    else
        max = 0;
    return max;

}

float Max::getMaxValue() const
{
   return maxValue;
}

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
    float min;
    if(subjects.size()!= 0){
        min = (*(subjects.begin()))->getValue();
        for(auto it : subjects){
            if(it->getValue() < min)
                min = it->getValue();
        }
    }
    else
        min = 0;
    return min;
}

float Min::getMinValue() const
{
    return minValue;
}

Cell *Min::getLastCellFound() const
{
    return lastCellFound;
}

bool Min::findCell(int row, int column)
{
    bool found = false;
    for(auto it : subjects){
        if(it->getRow() == row && it->getColumn() == column){
            found = true;
            lastCellFound = it;
            break;
        }
    }
    return found;
}

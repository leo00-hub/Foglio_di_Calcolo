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

float Sum::getSumValue() const
{
    return sumValue;
}

Cell *Sum::getLastCellFound() const
{
    return lastCellFound;
}

bool Sum::findCell(int row, int column)
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

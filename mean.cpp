#include "mean.h"
#include "cell.h"


void Mean::update()
{
    meanValue = compute();
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

float Mean::getMeanValue() const
{
    return meanValue;
}

Cell *Mean::getLastCellFound() const
{
    return lastCellFound;
}

float Mean::findCell(int row, int column)
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

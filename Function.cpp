#include "Function.h"
#include "cell.h"


bool Function::findCell(int row, int column){
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

Cell* Function::getLastCellFound() const
{
    return lastCellFound;
}

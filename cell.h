#ifndef CELL_H
#define CELL_H
#include "Subject.h"
#include "sum.h"
#include "mean.h"
#include "max.h"
#include "min.h"

class Cell : public Subject
{
public:
    Cell(Sum* s,Mean* me,Max* ma,Min* mi);
    virtual ~Cell();
    void attach() override;
    void detach() override;
    void notify() override;
    float getValue() const;
private:
    float value;
    Sum* sumFunction;
    Mean* meanFunction;
    Max* maxFunction;
    Min* minFunction;
};

#endif // CELL_H

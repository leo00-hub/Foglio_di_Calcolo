#include <QtTest>
#include <QCoreApplication>
#include "cell.h"
#include "cell.cpp"
#include "min.h"
#include "min.cpp"
#include "max.h"
#include "max.cpp"
#include "sum.h"
#include "sum.cpp"
#include "mean.h"
#include "mean.cpp"


class CellTest : public QObject
{
    Q_OBJECT
private slots:
   void test();
};

void CellTest::test(){
    Min minCell;
    Max maxCell;
    Mean meanCell;
    Sum sumCell;
    Cell cell_1(&sumCell,&meanCell,&maxCell,&minCell);
    Cell cell_2(&sumCell,&meanCell,&maxCell,&minCell);
    Cell cell_3(&sumCell,&meanCell,&maxCell,&minCell);
    cell_1.setValue(6);
    QCOMPARE(cell_1.getValue(),6);
    cell_2.setValue(4);
    QCOMPARE(cell_2.getValue(),4);
    cell_3.setValue(5);
    QCOMPARE(cell_3.getValue(),5);
    cell_3.detach();
    QCOMPARE(sumCell.getSumValue(),10);
    cell_2.detach();
    QCOMPARE(minCell.getMinValue(),6);
    cell_3.attach();
    QCOMPARE(sumCell.getSumValue(),11);
    cell_1.detach();
    QCOMPARE(maxCell.getMaxValue(),5);
;
}

QTEST_MAIN(CellTest)

#include "tst_celltest.moc"

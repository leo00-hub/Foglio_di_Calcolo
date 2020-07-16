#include <QtTest>
#include <QCoreApplication>
#include "sum.h"
#include "cell.h"
#include "sum.cpp"
#include "cell.cpp"
#include "Function.cpp"

class SumTest : public QObject
{
    Q_OBJECT
private slots:
  void test();
};

void SumTest::test(){
    Sum sumCell;
    Cell cell_1(&sumCell,nullptr,nullptr,nullptr);
    Cell cell_2(&sumCell,nullptr,nullptr,nullptr);
    Cell cell_3(&sumCell,nullptr,nullptr,nullptr);
    cell_1.setValue(4);
    cell_2.setValue(1);
    cell_3.setValue(-3);
    QCOMPARE(sumCell.getSumValue(),2);
    cell_3.detach();
    QCOMPARE(sumCell.getSumValue(),5);
    cell_2.detach();
    QCOMPARE(sumCell.getSumValue(),4);
    cell_1.setValue(10);
    QCOMPARE(sumCell.getSumValue(),10);
}
QTEST_MAIN(SumTest)

#include "tst_sumtest.moc"

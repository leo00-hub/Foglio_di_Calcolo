#include <QtTest>
#include <QCoreApplication>
#include "min.h"
#include "cell.h"
#include "min.cpp"
#include "cell.cpp"
#include "Function.cpp"

class MinTest : public QObject
{
    Q_OBJECT
private slots:
  void test();
};

void MinTest::test(){
    Min minCell;
    Cell cell_1(nullptr,nullptr,nullptr,&minCell);
    Cell cell_2(nullptr,nullptr,nullptr,&minCell);
    Cell cell_3(nullptr,nullptr,nullptr,&minCell);
    cell_1.setValue(3);
    cell_2.setValue(5);
    cell_3.setValue(-6);
    QCOMPARE(minCell.getMinValue(),-6);
    cell_3.detach();
    QCOMPARE(minCell.getMinValue(),3);
    cell_1.detach();
    QCOMPARE(minCell.getMinValue(),5);
    cell_2.setValue(-10);
    QCOMPARE(minCell.getMinValue(),-10);
}

QTEST_MAIN(MinTest)

#include "tst_mintest.moc"

#include <QtTest>
#include <QCoreApplication>
#include "max.h"
#include "cell.h"
#include "max.cpp"
#include "cell.cpp"


class MaxTest : public QObject
{
    Q_OBJECT
private slots:
    void test();
};
void MaxTest::test(){
    Max maxCell;
    Cell cell_1(nullptr,nullptr,&maxCell,nullptr);
    Cell cell_2(nullptr,nullptr,&maxCell,nullptr);
    Cell cell_3(nullptr,nullptr,&maxCell,nullptr);
    cell_1.setValue(2);
    cell_2.setValue(-3);
    cell_3.setValue(5);
    QCOMPARE(maxCell.getMaxValue(), 5);
    cell_3.detach();
    QCOMPARE(maxCell.getMaxValue() , 2);
    cell_1.detach();
    QCOMPARE(maxCell.getMaxValue() , -3);
    cell_2.setValue(8);
    QCOMPARE(maxCell.getMaxValue() , 8);
}
QTEST_MAIN(MaxTest)

#include "tst_maxtest.moc"

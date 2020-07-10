#include <QtTest>
#include <QCoreApplication>
#include "mean.h"
#include "cell.h"
#include "mean.cpp"
#include "cell.cpp"

class MeanTest : public QObject
{
    Q_OBJECT
private slots:
    void
    test();
};

void MeanTest::test(){
    Mean meanCell;
    Cell cell_1(nullptr,&meanCell,nullptr,nullptr);
    Cell cell_2(nullptr,&meanCell,nullptr,nullptr);
    Cell cell_3(nullptr,&meanCell,nullptr,nullptr);
    cell_1.setValue(3);
    cell_2.setValue(7);
    cell_3.setValue(2);
    QCOMPARE(meanCell.getMeanValue(),4);
    cell_3.detach();
    QCOMPARE(meanCell.getMeanValue(),5);
    cell_2.detach();
    QCOMPARE(meanCell.getMeanValue(),3);
    cell_1.setValue(6);
    QCOMPARE(meanCell.getMeanValue(),6);
}

QTEST_MAIN(MeanTest)

#include "tst_meantest.moc"

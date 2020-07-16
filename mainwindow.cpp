#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sumFunction = new Sum;
    meanFunction = new Mean;
    maxFunction = new Max;
    minFunction = new Min;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sumFunction;
    delete meanFunction;
    delete maxFunction;
    delete minFunction;
}


void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    QTableWidgetItem* q = ui->tableWidget->item(row,column);
    if(sumFunction->findCell(row,column)){
        Cell* cellChanged = sumFunction->getLastCellFound();
        if(q->text() != "")
            cellChanged ->setValue(q->text().toFloat());
        else
            cellChanged->detach();
    }
    else{
        Cell* cellChanged = new Cell(sumFunction,meanFunction,maxFunction,minFunction,row,column,q->text().toFloat());
        cellChanged->notify();
    }
    ui->sumCell->setPlainText(QString::number(sumFunction->getSumValue()));
    ui->meanCell->setPlainText(QString::number(meanFunction->getMeanValue()));
    ui->maxCell->setPlainText(QString::number(maxFunction->getMaxValue()));
    ui->minCell->setPlainText(QString::number(minFunction->getMinValue()));
}


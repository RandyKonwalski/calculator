#include "calcwindow.h"
#include "ui_calcwindow.h"


CalcWindow::CalcWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalcWindow)
{
    ui->setupUi(this);

    connect(ui->Button_0, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_1, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_2, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_3, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_4, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_5, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_6, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_7, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_8, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->Button_9, SIGNAL(released()), this, SLOT(NumPressed()));

    connect(ui->Button_ADD, SIGNAL(released()), this, SLOT(FuncPressed()));
    connect(ui->Button_SUB, SIGNAL(released()), this, SLOT(FuncPressed()));
    connect(ui->Button_MUL, SIGNAL(released()), this, SLOT(FuncPressed()));
    connect(ui->Button_DIV, SIGNAL(released()), this, SLOT(FuncPressed()));
}

CalcWindow::~CalcWindow()
{
    delete ui;
}

void CalcWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString valuebtn = button->text();
    QString valueline = ui->lineEdit->text();
    if(valueline.toDouble() == 0){
        ui->lineEdit->setText(valuebtn);
    } else {
        QString valueend = valueline + valuebtn;
        ui->lineEdit->setText(valueend);
    }
}

void CalcWindow::FuncPressed(){

}

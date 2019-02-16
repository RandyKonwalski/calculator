#include "calcwindow.h"
#include "ui_calcwindow.h"

bool mul = false;
bool add = false;
bool sub = false;
bool divs = false;
double lastval = 0.0;
double curval = 0.0;

CalcWindow::CalcWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalcWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setText("0.0");

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
    connect(ui->Button_EQ, SIGNAL(released()), this, SLOT(FuncPressed()));

    connect(ui->Button_CE, SIGNAL(released()), this, SLOT(CEPressed()));
    connect(ui->Button_C, SIGNAL(released()), this, SLOT(CPressed()));

    connect(ui->Button_DOT, SIGNAL(released()), this, SLOT(DotPressed()));
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

void CalcWindow::CEPressed(){
    ui->lineEdit->clear();
    divs = false;
    mul = false;
    add = false;
    sub = false;
}

void CalcWindow::CPressed(){
    ui->lineEdit->clear();
}

void CalcWindow::DotPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString valueline = ui->lineEdit->text();
    if(valueline.toDouble() != 0){
        QString valueend = valueline + ".";
        ui->lineEdit->setText(valueend);
    }
}

void CalcWindow::FuncPressed(){
    QPushButton *button = (QPushButton *)sender();
    curval = ui->lineEdit->text().toDouble();
    double newval = 0;
    if(QString::compare(button->text(), "/", Qt::CaseSensitive) == 0){
        divs = true;
        lastval = curval;
        ui->lineEdit->clear();
    } else if(QString::compare(button->text(), "*", Qt::CaseInsensitive) == 0){
        mul = true;
        lastval = curval;
        ui->lineEdit->clear();
    } else if(QString::compare(button->text(), "+", Qt::CaseInsensitive) == 0){
        add = true;
        lastval = curval;
        ui->lineEdit->clear();
    } else if(QString::compare(button->text(), "-", Qt::CaseInsensitive) == 0){
        sub = true;
        lastval = curval;
        ui->lineEdit->clear();
    } else if(QString::compare(button->text(), "=", Qt::CaseInsensitive) == 0){
        if(divs == true){
            newval = lastval / curval;
            ui->lineEdit->setText(QString::number(newval));
        } else if(mul == true){
            newval = lastval * curval;
            ui->lineEdit->setText(QString::number(newval));
        } else if(add == true){
            newval = lastval + curval;
            ui->lineEdit->setText(QString::number(newval));
        } else if(sub == true){
            newval = lastval - curval;
            ui->lineEdit->setText(QString::number(newval));
        } else {
        }
    }
}

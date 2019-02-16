#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QMainWindow>

namespace Ui {
class CalcWindow;
}

class CalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalcWindow(QWidget *parent = 0);
    ~CalcWindow();

private slots:
    void NumPressed();
    void FuncPressed();

private:
    Ui::CalcWindow *ui;
};

#endif // CALCWINDOW_H

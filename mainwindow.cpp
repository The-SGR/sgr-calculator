#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>

double firstNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui -> Btn0, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn1, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn2, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn3, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn4, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn5, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn6, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn7, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn8, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> Btn9, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui -> negateBtn, SIGNAL(clicked()), this, SLOT(conversion()));
    connect(ui -> addBtn, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> subtractBtn, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> multiplyBtn, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> divideBtn, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> percentBtn, SIGNAL(clicked()), this, SLOT(conversion()));
    connect(ui -> sqrtBtn, SIGNAL(clicked()), this, SLOT(conversion()));
    connect(ui -> cbrtBtn, SIGNAL(clicked()), this, SLOT(conversion()));
    connect(ui -> factorBtn, SIGNAL(clicked()), this, SLOT(conversion()));
    connect(ui -> power2Btn, SIGNAL(clicked()), this, SLOT(conversion()));
    connect(ui -> powerYBtn, SIGNAL(clicked()), this, SLOT(operations()));

    ui -> addBtn -> setCheckable(true);
    ui -> subtractBtn -> setCheckable(true);
    ui -> multiplyBtn -> setCheckable(true);
    ui -> divideBtn -> setCheckable(true);
    ui -> powerYBtn -> setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits() {
    QPushButton *btn = (QPushButton *)sender();
    double nums;
    QString newLabel;

    nums = (ui -> resShow -> text() + btn -> text()).toDouble();
    newLabel = QString::number(nums, 'g', 16);
    ui -> resShow -> setText(newLabel);
}

void MainWindow::conversion() {
    QPushButton *btn = (QPushButton *)sender();
    double nums;
    QString newLabel;

    if (btn -> text() == "+/-") {
        nums = (ui -> resShow -> text()).toDouble();
        nums *= -1;
        newLabel = QString::number(nums, 'g', 16);
        ui -> resShow -> setText(newLabel);
    } else if (btn -> text() == "%") {
        nums = (ui -> resShow -> text()).toDouble();
        nums *= 0.01;
        newLabel = QString::number(nums, 'g', 16);
        ui -> resShow -> setText(newLabel);
    } else if (btn -> text() == "sqrt") {
        nums = (ui -> resShow -> text()).toDouble();
        nums = sqrt(nums);
        newLabel = QString::number(nums, 'g', 16);
        ui -> resShow -> setText(newLabel);
    } else if (btn -> text() == "x^2") {
        nums = (ui -> resShow -> text()).toDouble();
        nums *= nums;
        newLabel = QString::number(nums, 'g', 16);
        ui -> resShow -> setText(newLabel);
    } else if (btn -> text() == "cbrt") {
        nums = (ui -> resShow -> text()).toDouble();
        nums = cbrt(nums);
        newLabel = QString::number(nums, 'g', 16);
        ui -> resShow -> setText(newLabel);
    } else if (btn -> text() == "x!") {
        nums = (ui -> resShow -> text()).toInt();
        if (nums < 0) {
            ui -> resShow -> setText("Math Error");
        }
        long res = 1;
        for (int i = 1; i <= nums; i++) {
            res *= i;
        }
        newLabel = QString::number(res, 'g', 16);
        ui -> resShow -> setText(newLabel);
    }
}

void MainWindow::operations() {
    QPushButton *btn = (QPushButton *)sender();
    firstNum = ui -> resShow -> text().toDouble();
    ui -> resShow -> setText(" ");
    btn -> setChecked(true);
}

void MainWindow::on_dotBtn_clicked()
{
    if (!(ui -> resShow -> text().contains('.'))) {
        ui -> resShow -> setText(ui -> resShow -> text() + ".");
    }
}

void MainWindow::on_equalBtn_clicked()
{
    double labelNum, secondNum;
    QString newLabel;
    secondNum = ui -> resShow -> text().toDouble();

    if (ui -> addBtn -> isChecked()) {
        labelNum = firstNum + secondNum;
        newLabel = QString::number(labelNum, 'g', 16);

        ui -> resShow -> setText(newLabel);
        ui -> addBtn -> setChecked(false);
    } else if (ui -> subtractBtn -> isChecked()) {
        labelNum = firstNum - secondNum;
        newLabel = QString::number(labelNum, 'g', 16);

        ui -> resShow -> setText(newLabel);
        ui -> subtractBtn -> setChecked(false);
    } else if (ui -> multiplyBtn -> isChecked()) {
        labelNum = firstNum * secondNum;
        newLabel = QString::number(labelNum, 'g', 16);

        ui -> resShow -> setText(newLabel);
        ui -> multiplyBtn -> setChecked(false);
    } else if (ui -> divideBtn -> isChecked()) {
        if (secondNum == 0) {
            ui -> resShow -> setText("+inf, -inf");
        } else {
            labelNum = firstNum / secondNum;
            newLabel = QString::number(labelNum, 'g', 16);

            ui -> resShow -> setText(newLabel);
            ui -> divideBtn -> setChecked(false);
        }
    } else if (ui -> powerYBtn -> isChecked()) {
        labelNum = pow(firstNum, secondNum);
        newLabel = QString::number(labelNum, 'g', 16);

        ui -> resShow -> setText(newLabel);
        ui -> multiplyBtn -> setChecked(false);
    }
}

void MainWindow::on_clearBtn_clicked()
{
    ui -> addBtn -> setChecked(false);
    ui -> subtractBtn -> setChecked(false);
    ui -> multiplyBtn -> setChecked(false);
    ui -> divideBtn -> setChecked(false);
    ui -> powerYBtn -> setChecked(false);
    ui -> resShow -> setText("0");
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits();
    void on_dotBtn_clicked();
    void conversion();
    void operations();
    void on_clearBtn_clicked();
    void on_equalBtn_clicked();
};
#endif // MAINWINDOW_H

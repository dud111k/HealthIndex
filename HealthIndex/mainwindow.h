#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QLabel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void OnAddClicked();

private:
    Ui::MainWindow *ui;
    QLineEdit* heightInput;
    QLineEdit* weightInput;
    QLabel* bmiLabel;
    QLabel* answerLabel;

};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFrame>
#include <QHBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    QWidget* centralWidget = new QWidget;
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    centralWidget -> setLayout(mainLayout);

    mainLayout -> addWidget(new QLabel("Введите вес:"));
    weightInput = new QLineEdit;
    weightInput->setPlaceholderText("кг");
    mainLayout -> addWidget(weightInput);

    QFrame* horizontalLine = new QFrame();
    horizontalLine->setFrameShape(QFrame::HLine);
    horizontalLine->setLineWidth(2);
    mainLayout -> addWidget(horizontalLine);

    mainLayout -> addWidget(new QLabel("Введите рост:"));
    heightInput = new QLineEdit();

    heightInput->setPlaceholderText("см");
    mainLayout -> addWidget(heightInput);


    QFrame* horizontalLine1 = new QFrame();
    horizontalLine1->setFrameShape(QFrame::HLine);
    horizontalLine1->setLineWidth(2);
    mainLayout -> addWidget(horizontalLine1);

    QFrame* horizontalLine2 = new QFrame();
    horizontalLine2->setFrameShape(QFrame::HLine);
    horizontalLine2->setLineWidth(2);
    mainLayout -> addWidget(horizontalLine2);

    QPushButton* bmiButton = new QPushButton("Рассчитать ИМТ");
    mainLayout->addWidget(bmiButton);
    connect(bmiButton, &QPushButton::clicked, this, &MainWindow::OnAddClicked);

    bmiLabel = new QLabel("ИМТ:", this);
    answerLabel = new QLabel(this);

    mainLayout->addWidget(bmiLabel);
    mainLayout->addWidget(answerLabel);



}

MainWindow::~MainWindow()
{
}
    void MainWindow::OnAddClicked()
{
    bool heightOk, weightOk;
    double height = heightInput->text().toDouble(&heightOk) / 100;
    double weight = weightInput->text().toDouble(&weightOk);

    if (!heightOk || !weightOk || height <= 0 || weight <= 0) {
        QMessageBox::warning(this, "Ошибка", "Введите корректные значения роста и веса");
        return;
    }

    double bmi = weight / (height * height);
    bmiLabel->setText(QString("ИМТ: %1").arg(bmi, 0, 'f', 1));

    QString answer;
    if (bmi < 16.0) answer = "Выраженный дефицит веса";
    else if (bmi < 18.5) answer = "Недостаточный вес";
    else if (bmi < 25) answer = "Нормальный вес";
    else if (bmi < 30) answer = "Избыточный вес";
    else if (bmi < 35) answer = "Ожирение 1-й степени";
    else if (bmi < 40) answer = "Ожирение 2-й степени";
    else answer = "Ожирение 3-й степени";

    answerLabel->setText(answer);

}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->slider_1, SLOT(setValue(int)));
    QObject::connect(ui->slider_1, SIGNAL(valueChanged(int)),ui->spinBox, SLOT(setValue(int)));
    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->slider_2, SLOT(setValue(int)));
    QObject::connect(ui->slider_2, SIGNAL(valueChanged(int)),ui->spinBox_2 , SLOT(setValue(int)));
    QObject::connect(ui->spinBox_2,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->spinBox_3, SIGNAL(valueChanged(int)), ui->slider_3, SLOT(setValue(int)));
    QObject::connect(ui->slider_3, SIGNAL(valueChanged(int)),ui->spinBox_3 , SLOT(setValue(int)));
    QObject::connect(ui->spinBox_3,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->spinBox_4, SIGNAL(valueChanged(int)), ui->slider_4, SLOT(setValue(int)));
    QObject::connect(ui->slider_4, SIGNAL(valueChanged(int)),ui->spinBox_4, SLOT(setValue(int)));
    QObject::connect(ui->spinBox_4,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->spinBox_5, SIGNAL(valueChanged(int)), ui->slider_5, SLOT(setValue(int)));
    QObject::connect(ui->slider_5, SIGNAL(valueChanged(int)),ui->spinBox_5, SLOT(setValue(int)));
    QObject::connect(ui->spinBox_5,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->spinBox_6, SIGNAL(valueChanged(int)), ui->slider_6, SLOT(setValue(int)));
    QObject::connect(ui->slider_6, SIGNAL(valueChanged(int)),ui->spinBox_6, SLOT(setValue(int)));
    QObject::connect(ui->spinBox_6,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->spinBox_7, SIGNAL(valueChanged(int)), ui->slider_7, SLOT(setValue(int)));
    QObject::connect(ui->slider_7, SIGNAL(valueChanged(int)),ui->spinBox_7, SLOT(setValue(int)));
    QObject::connect(ui->spinBox_7,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->spinBox_8, SIGNAL(valueChanged(int)), ui->slider_8, SLOT(setValue(int)));
    QObject::connect(ui->slider_8, SIGNAL(valueChanged(int)),ui->spinBox_8, SLOT(setValue(int)));
    QObject::connect(ui->spinBox_8,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->midterm_spinBox_1, SIGNAL(valueChanged(int)), ui->vertSlider_1, SLOT(setValue(int)));
    QObject::connect(ui->vertSlider_1, SIGNAL(valueChanged(int)),ui->midterm_spinBox_1, SLOT(setValue(int)));
    QObject::connect(ui->midterm_spinBox_1,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->midterm_spinBox_2, SIGNAL(valueChanged(int)), ui->vertSlider_2, SLOT(setValue(int)));
    QObject::connect(ui->vertSlider_2, SIGNAL(valueChanged(int)),ui->midterm_spinBox_2 , SLOT(setValue(int)));
    QObject::connect(ui->midterm_spinBox_2,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->final_spinBox, SIGNAL(valueChanged(int)), ui->vertSlider_3, SLOT(setValue(int)));
    QObject::connect(ui->vertSlider_3, SIGNAL(valueChanged(int)),ui->final_spinBox, SLOT(setValue(int)));
    QObject::connect(ui->final_spinBox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->schemaPicker,SIGNAL(currentTextChanged(QString)), this, SLOT(update_schema(QString)));
    QObject::connect(ui->classPicker,SIGNAL(currentTextChanged(QString)), this, SLOT(update_class(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_schema(QString schema){
    update_overall(0);
}

void MainWindow::update_class(QString schema){
    if(schema == "PIC 10B -- Intermediate Programming"){
        ui->spinBox->show();
        ui->spinBox_2->show();
        ui->spinBox_3->show();
        ui->spinBox_4->show();
        ui->spinBox_5->show();

        ui->slider_1->show();
        ui->slider_2->show();
        ui->slider_3->show();
        ui->slider_4->show();
        ui->slider_5->show();

        ui->label_5->show();
        ui->label_6->show();
        ui->label_7->show();
        ui->label_8->show();
        ui->label->show();


        ui->midterm_2->show();
        ui->vertSlider_2->show();
    }
    else{
        ui->spinBox->close();
        ui->spinBox_2->close();
        ui->spinBox_3->close();
        ui->spinBox_4->close();
        ui->spinBox_5->close();

        ui->slider_1->close();
        ui->slider_2->close();
        ui->slider_3->close();
        ui->slider_4->close();
        ui->slider_5->close();

        ui->label_5->close();
        ui->label_6->close();
        ui->label_7->close();
        ui->label_8->close();
        ui->label->close();

        ui->midterm_2->close();
        ui->vertSlider_2->close();

    }
}

void MainWindow::update_overall(int unused)
{
    int hmwScore, midterm_1, midterm_2;
    int final = ui->final_spinBox->value();
    double score;
    if(ui->classPicker->currentText() == "PIC 10B -- Intermediate Programming"){
        hmwScore = ui->spinBox->value() + ui->spinBox_2->value() +
                       ui->spinBox_3->value() + ui->spinBox_4->value() +
                       ui->spinBox_5->value() + ui->spinBox_6->value() +
                       ui->spinBox_7->value() + ui->spinBox_8->value();

        midterm_1 = ui->midterm_spinBox_1->value();
        midterm_2 = ui->midterm_spinBox_2->value();

        if(ui->schemaPicker->currentText() == "Schema A"){
            score = static_cast<double>((0.25)*hmwScore + (0.2)*midterm_1 + (0.2)*midterm_2 + (0.35)*final);
        }
        else{
            if(midterm_1 > midterm_2){
                score = static_cast<double>((0.25)*hmwScore + (0.3)*midterm_1 + (0.44)*final);
            }
            else{
                score = static_cast<double>((0.25)*hmwScore + (0.3)*midterm_2 + (0.44)*final);
            }
        }
    }
    else{
        hmwScore = ui->spinBox->value() + ui->spinBox_2->value() +
                       ui->spinBox_3->value();

        midterm_1 = ui->midterm_spinBox_1->value();

        if(ui->schemaPicker->currentText() == "Schema A"){
            score = static_cast<double>((0.25)*hmwScore + (0.2)*midterm_1 + (0.35)*final);
        }
        else{
            score = static_cast<double>((0.25)*hmwScore + (0.74)*final);

        }

    }

    //ui->label->setText(ui->schemaPicker->currentText());
    ui->score->setText(QString::number(score));

    return;
}


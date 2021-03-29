#include "lifewindow.h"
#include "ui_lifewindow.h"
#include <QDebug>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_speed_label(int speed)
{
    QString str = "Speed: ";
    QString n = QString::number(speed);
    str.append(n);
    ui->speed_label->setText(str);
}

void MainWindow::on_step_button_clicked()
{
    // next turn
    // update turn counter
}

void MainWindow::on_speed_slider_valueChanged(int value)
{
    // ranges from 0 to 99
    // update Speed display
    // update speed modifier in game logic
    qDebug() << "New Speed: " << value;
    this->update_speed_label(value);
}

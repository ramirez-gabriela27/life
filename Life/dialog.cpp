#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
//    Your playing field mustbe at least20 cells wide and 10 cells tall.
    QValidator *validator_height = new QIntValidator(10, 99, this);
    QValidator *validator_width = new QIntValidator(20, 99, this);
    // the edit lineedit will only accept integers between 100 and 999
    ui->lineEdit->setValidator(validator_height);
    ui->lineEdit_2->setValidator(validator_width);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    bool safe = false;
    int width = ui->lineEdit->text().toInt(&safe);
    int height = ui->lineEdit_2->text().toInt(&safe);

    this->set_width(width);
    this->set_height(height);


    if (width == 0 || height == 0) {
        reject();
        qDebug() << "Reject";
        QMessageBox msgBox;
        msgBox.setText("You must fill both fields!");
        msgBox.exec();
    }
    else if (width <= 19 || height <= 9) {
        reject();
        qDebug() << "Reject";
        QMessageBox msgBox;
        msgBox.setText("Must be proper dimensions!");
        msgBox.exec();

    }
    else {
        accept();
        qDebug() << "Game created !";
        qDebug() << "Width set to " << width;
        qDebug() << "Height set to " << height;
        // send signal of height and width to mainwindow

        // create new game object
    }


}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

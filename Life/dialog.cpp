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
    QValidator *validator = new QIntValidator(1, 99, this);

    // the edit lineedit will only accept integers between 100 and 999
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);

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

    qDebug() << "Width set to " << width;
    qDebug() << "Height set to " << height;
    if (width == 0 || height == 0) {
        reject();
        qDebug() << "Reject";
        QMessageBox msgBox;
        msgBox.setText("You must fill both fields!");
        msgBox.exec();
    }
    else
        accept();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QColorDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Life Application");
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_game_coordinates(int height, int width) {
    qDebug() << "Creating game instance! " << height<< ", " << width;
    Game *g = new Game(height, width);
    this->set_game(g);

}

// Updates label text on UI
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
    qDebug() << "Step";
}

void MainWindow::on_speed_slider_valueChanged(int value)
{
    // ranges from 0 to 99
    // update Speed display
    // update speed modifier in game logic
    qDebug() << "New Speed: " << value;
    this->update_speed_label(value);
}

void MainWindow::on_actionNew_Game_triggered()
{
    Dialog *dialog = new Dialog(this);
    dialog->open();
    connect(dialog, &Dialog::send_coordinates, this , &MainWindow::get_game_coordinates);
    // if game exists, clear screen


//    qDebug() << "New game created!";
    // create dialogue window
}

void MainWindow::on_actionChange_Color_triggered()
{
    // default color is red
    QColor color = QColorDialog::getColor(Qt::red,this,"Cell Color");
    if(color.isValid()) { // if color is chosen by dialog

    }
}

void MainWindow::on_play_button_clicked()
{
    qDebug() << "Playing game...";
}

void MainWindow::on_pause_button_clicked()
{
    qDebug() << "Game paused";
}

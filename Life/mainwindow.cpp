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
    QGraphicsView * view = ui->grid_view;
    scene = new QGraphicsScene;
    view->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_game_coordinates(int height, int width)
{
    qDebug() << "Creating game instance! " << height<< ", " << width;
    if (this->get_game() != nullptr) {
        qDebug() << "Deleting old game reference...";
        // destroy old game instance
        delete g_;
        /*g_ = nullptr*/;
    }
    scene->clear();
    Game *g = new Game(height, width);
//    connect(g, &Game::send_update_display,this, &MainWindow::update_display);
    this->set_height(height);
    this->set_width(width);

    this->set_game(g);

    this->create_graph();

    this->create_grid();

}

// Updates label text on UI
void MainWindow::update_speed_label(int speed)
{
    QString str = "Speed: ";
    QString n = QString::number(speed);
    str.append(n);
    ui->speed_label->setText(str);
}

void MainWindow::update_turn_label(int count)
{
    QString str = "Turn: ";
    QString n = QString::number(count);
    str.append(n);
    ui->turn_label->setText(str);
}

void MainWindow::on_step_button_clicked()
{
    // next turn
    // update turn counter
    qDebug() << "Step";
    Game*g = get_game();
    g->take_turn();
    qDebug() << "taking turn" << g->get_turns();
    this->update_turn_label(g->get_turns());
    update();
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
        // change every live color
        Game* g = get_game();
        std::vector<std::vector<Cell*>> vec = g->get_game_vec();
        //check neighbors and update cell state
        for (int i = 0; i < g->get_width(); i++){
            for (int j = 0; j < g->get_height(); j++){
                g->set_color(color);
                //scene->addItem(vec[j][i]);
                update();
            }
        }
    }
}

void MainWindow::on_play_button_clicked()
{
    qDebug() << "Playing game...";
    Game* g = get_game();
    g->set_status(false);//game is not paused
    g->play_game();

}

void MainWindow::on_pause_button_clicked()
{
    qDebug() << "Game paused";
    Game* g = get_game();
    g->set_status(true);//game is paused
    // send signal to game that it is paused
}

void MainWindow::create_grid(){

    // generate grid of height h and width w
    // gridview set geometry

    Game* g = get_game();
    std::vector<std::vector<Cell*>> vec = g->get_game_vec();
    int h = this->get_height();
    int w = this->get_width();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scene->addItem(vec[j][i]);
        }
    }

    return;
}

void MainWindow::create_graph(){
    return;
}


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

void MainWindow::update_grid(){
    //to take the turn, we update counter
    int t = this->get_game()->get_turn_count();
    t++;
    this->get_game()->set_turn_count(t);
    qDebug() << "taking turn # " << this->get_game()->get_turn_count();
    //update the cells and the graph
    qDebug() << "in update grid function";
    //check neighbors and update cell state
    std::vector<std::vector<Cell*>> cells_ = this->get_game()->get_game_vec();
    for (int i = 0; i < width_; i++){
        for (int j = 0; j < height_; j++){
            //generate neighbor count of living cells
            int live_neighbors = 0;

            //now we look at the buddies and add to the counter
            //gotta check 8 buddies
            if(i == width_-1 && j == height_-1){
                //if at the conrner (bottom right), only check inner ones
                if(cells_[i-1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i][j-1]->get_curr_state()){ live_neighbors++;}
            }else if(i == 0 && j == 0){
                //if at corner (top left)
                if(cells_[i][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j]->get_curr_state()){ live_neighbors++;}
            }else if(i == width_-1 && j == 0){
                //if at the conrner (top right), only check inner ones
                if(cells_[i][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j+1]->get_curr_state()){ live_neighbors++;}
            }else if(i == 0 && j == height_-1){
                //if at corner (bottom left)
                if(cells_[i][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j]->get_curr_state()){ live_neighbors++;}
            }


            else if( i == 0){
                //lining the edges(entire left line) except for conrner
                if(cells_[i][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j+1]->get_curr_state()){ live_neighbors++;}
            }else if( i == width_-1){
                //lining the edges(entire right line) except for corner
                if(cells_[i-1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i][j-1]->get_curr_state()){ live_neighbors++;}

            }else if( j == 0){
                //lining the edges(entire top line) except for conrner
                if(cells_[i][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j]->get_curr_state()){ live_neighbors++;}
            }else if( j == height_-1){
                //lining the edges(entire bottom line) except for corner
                if(cells_[i][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j]->get_curr_state()){ live_neighbors++;}
            }
            //all other cells
            else{
                if(cells_[i-1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j+1]->get_curr_state()){ live_neighbors++;}
            }
            qDebug() << live_neighbors << " alive around cell (" << i << " ," << j << ")";

            if(!cells_[i][j]->get_curr_state()){
                //if the cell is dead, but has 3 live neighbors, it is now alive
                if(live_neighbors == 3){
                    cells_[i][j]->set_curr_state(true);
                    cells_[i][j]->set_color(this->get_color());
                    qDebug() << "she lives!";
                    update();
                }//otherwise, stay dead

            }else{//if the cell is alive
                if(live_neighbors < 2 || live_neighbors > 3){
                    //and has less than 2 or more than 3 live neighbors, it dies
                    cells_[i][j]->set_curr_state(false);
                    //if she dead, change color to white
                    cells_[i][j]->set_color(Qt::white);
                    update();
                    qDebug() << "she dead now";
                }
                //if(live_neighbors == 2 || live_neighbors == 3){
                    //if the cell is alive, and has 2 or 3 live neighbors, it lives still
                    //no need to test for this condition, for it will be the last and
                    //all others are alread tested -- state won't change
                    //cells_[i][j]->set_curr_state(true);
                //}
            }

        }
    }

    //display it by updating the grid
    //*****code here
//    emit send_update_display();
}

void MainWindow::on_step_button_clicked()
{
    // next turn
    // update turn counter
    qDebug() << "Step";
    Game*g = get_game();
//    g->take_turn();
    this->update_grid();
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
    this->set_color(color);
    if(color.isValid()) { // if color is chosen by dialog
        // change every live color
        Game* g = this->get_game();
        auto vec = g->get_game_vec();
        for (int i = 0; i < g->get_width(); i++) {
            for (int j = 0; j < g->get_height(); j++) {
                if (vec[i][j]->get_curr_state()) {
                    vec[i][j]->set_color(color);
                    update();
                }
            }
        }
    }
}

void MainWindow::on_play_button_clicked()
{
    // we wanted to get the speed working, but couldn't figure out how to stop the play button

    qDebug() << "Playing game...";
    Game* g = get_game();
    g->set_status(false);//game is not paused
    while(!g->get_status()) {
        this->update_grid();
        this->update_turn_label(g->get_turns());
    }


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


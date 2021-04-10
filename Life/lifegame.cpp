#include "lifegame.h"
#include <stdlib.h> // srand
#include <time.h>
#include <QDebug>
#include <QWidget>
//location struct
//cell class finished in header
//game class needs completion

/*
    Cell constructor
*/
Cell::Cell(QColor color, int x, int y){
    color_ = color;
    location_.x_ = x;
    location_.y_ = y;
}
///////////////
/*
    Game Constructor
*/
Game::Game(int h, int w){
    height_ = h;
    widtht_ = w;
    turn_count_ = 0;
    srand (time(NULL));

    //create and populate vector of cells
    for (int i = 0; i < w; i++){
        std::vector<Cell*> rows_;
        for (int j = 0; j < h; j++){
            //create location
            Location l;
            l.x_ = i;
            l.y_ = j;
            int temp = rand()%2;
//            qDebug() << temp;
            bool state = bool(temp);
            Cell *c = new Cell(Qt::white, i, j); //default color to white (dead)
            c->set_curr_state(state);
            // set live cells to gray
            if (state) {
                c->set_color(QColor(128, 128, 128));              
            }
            rows_.push_back(c);
            // display cell object on UI

        }
        cells_.push_back(rows_);
    }

//    create_grid();
//    create_graph();
}

/*
    Take a turn - update the cells/grid, update the graph, update counters
        will take turns while the game is not paused, if it is paused, will take turn on "Step" press
    @param N/A
    @return N/A

*/
void Game::take_turn(){
    //to take the turn, we update counter
    turn_count_++;
    qDebug() << "taking turn # " << turn_count_;
    //update the cells and the graph
    update_grid();
    update_graph();
}

//void Game::create_grid(){

//    // generate grid of height h and width w

//    return;
//}

//void Game::create_graph(){
//    return;
//}

void Game::start_simulation(){
    return;
}

void Game::update_grid(){
    qDebug() << "in update grid function";
    //check neighbors and update cell state
    for (int i = 0; i < widtht_; i++){
        for (int j = 0; j < height_; j++){
            //generate neighbor count of living cells
            int live_neighbors = 0;

            //now we look at the buddies and add to the counter
            //gotta check 8 buddies
            if(i == widtht_-1 && j == height_-1){
                //if at the conrner (bottom right), only check inner ones
                if(cells_[i-1][j-1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i-1][j]->get_curr_state()){ live_neighbors++;}
                if(cells_[i][j-1]->get_curr_state()){ live_neighbors++;}
            }else if(i == 0 && j == 0){
                //if at corner (top left)
                if(cells_[i][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j+1]->get_curr_state()){ live_neighbors++;}
                if(cells_[i+1][j]->get_curr_state()){ live_neighbors++;}
            }else if(i == widtht_-1 && j == 0){
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
            }else if( i == widtht_-1){
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
                    qDebug() << "she lives!";
                }//otherwise, stay dead

            }else{//if the cell is alive
                if(live_neighbors < 2 || live_neighbors > 3){
                    //and has less than 2 or more than 3 live neighbors, it dies
                    cells_[i][j]->set_curr_state(false);
                    //if she dead, change color to white
                    cells_[i][j]->set_color(Qt::white);
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

void Game::update_graph(){
    return;
}

QRectF Cell::boundingRect() const
{
    return QRectF(location_.x_, location_.y_, 20, 20);
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    // 20x20 pixel square
    // draws from upper left hand corner
    painter->setBrush(QBrush(color_));
    qDebug() << "Coord:" << this->get_location().x_ << ", " << this->get_location().y_;
    painter->drawRect(QRect(this->get_location().x_*20-440, this->get_location().y_*20-215, 20, 20));

    // draw rectangle
    painter->setBrush(b);
}

void Game::play_game() {

    while(!this->get_status()){
        this->take_turn();
//        this->update_turn_label(g->get_turns());

    }
}

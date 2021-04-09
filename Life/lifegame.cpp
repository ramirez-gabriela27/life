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
            qDebug() << temp;
            bool state = bool(temp);
            Cell *c = new Cell(Qt::white, i, j);
            c->set_curr_state(state);
            // set dead cells to white

            rows_.push_back(c);
            // display cell object on UI

        }
        cells_.push_back(rows_);
    }

    create_grid();
    create_graph();
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
    //update the cells and the graph
    update_grid();
    update_graph();
}

void Game::start_game(){
    return;
}

void Game::create_grid(){


    return;
}

void Game::create_graph(){
    return;
}

void Game::start_simulation(){
    return;
}

void Game::update_grid(){
    return;
}

void Game::update_graph(){
    return;
}

void Game::pause_simulation(){
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
    painter->setBrush(QBrush(color_));
    // draw rectangle
    painter->setBrush(b);
}

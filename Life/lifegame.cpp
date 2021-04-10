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
    width_ = w;
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



//void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    qDebug() << "Cell clicked!";

//    if (event->button() == Qt::RightButton) {
//        qDebug() << "right button clicked!";
//        this->set_curr_state(false);
//        update();

//    }
//    else if (event->button() == Qt::LeftButton) {
//        qDebug() << "shift clicked!";
//        this->set_curr_state(true);
//        update();
//    }
//}

void Game::start_simulation(){
    return;
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

//void Game::play_game() {

//    while(!this->get_status()){
//        this->take_turn();
////        this->update_turn_label(g->get_turns());

//    }
//}

#include "lifegame.h"
#include <stdlib.h> // srand
#include <time.h>
#include <QDebug>
//location struct
//cell class finished in header
//game class needs completion

/*
    Cell constructor
*/
Cell::Cell(){
    color_ = QColor(128, 128, 128);
}
///////////////
/*
    Game Constructor
*/
Game::Game(int h, int w){
    height_ = h;
    widtht_ = w;

    //create and populate vector of cells
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            //create location
            Location l;
            l.x_ = i;
            l.y_ = j;
            srand (time(NULL));
            int temp = rand()%2+1;
            qDebug() << temp;
            bool state = bool(temp);
            Cell *c = new Cell();
            c->set_curr_state(state);

//            Cell *c = new Cell();
//            cells_[i][j] = c;
        }
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

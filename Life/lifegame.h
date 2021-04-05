#ifndef LIFEGAME_H
#define LIFEGAME_H

#include <QColor>

struct Location{
    int x_;
    int y_;
};

class Cell{
public:
    //getters
    Location get_location(){ return location_; };
    QColor get_color() { return color_; };
    bool get_curr_state(){ return state_; };
    bool get_next_state(){ return next_state_; };
    //setters
    void set_location(Location l) { location_ = l; };
    void set_color (QColor c){ color_ = c; };
    void set_curr_state(bool s){ state_ = s; };
    void set_next_state(bool s){ next_state_ = s; };
private:
    Location location_;
    QColor color_;
    bool state_; //true for alive, false for dead
    bool next_state_; //^^
};

class Game{
public:
    //getters
    int get_turns(){ return turn_count_; };
    //setters
    void set_speed(int s){ speed_ = s; };
    void pause_simulation(bool p){ is_paused_ = p; };
    //member functions
    void take_turn();
    void start_game();
        //will call on these
        void create_grid();
        void create_graph();
        void start_simulation();
    void update_grid();
    void update_graph();
    void pause_simulation();
private:
    int turn_count_;
    int speed_;
    bool is_paused_;
};

#endif // LIFEGAME_H
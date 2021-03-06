#ifndef LIFEGAME_H
#define LIFEGAME_H

#include <QColor>
#include <QGraphicsItem>
#include <QPainter>
#include <QBrush>
struct Location{
    int x_;
    int y_;
};

class Cell : public QGraphicsItem{

    // this makes it so that we can emit signals

public:
    Cell(QColor color, const int x, const int y);
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
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;


private:
    Location location_;
    QColor color_;
    bool state_; //true for alive, false for dead
    bool next_state_; //^^
    int x_;
    int y_;
    std::vector<Cell> neighbors_;
};


class Game{

    // this makes it so that we can emit signals
public:

    // make this singleton
    // creates 2D vector of Cell objects. Has them displayed on mainwindow
    Game(int height, int width);

//    ~Game();

    //getters
    int get_turns(){ return turn_count_; };
    bool get_status(){ return is_paused_; };
    int get_width(){ return widtht_; };
    int get_height(){ return height_; };
    std::vector<std::vector<Cell*>> get_game_vec() { return cells_;};
    //setters
    void set_color(QColor c);
    void set_speed(int s){ speed_ = s; };
    void set_status(bool p){ is_paused_ = p; };
    //member functions
    void take_turn();
    void play_game();
        //will call on these
//        void create_grid();
//        void create_graph();
    void start_simulation();
    void update_grid();
    void update_graph();
signals:
    void send_update_display();

private:
    int turn_count_;
    int speed_;
    bool is_paused_;
    int height_;    //height of the grid of cells
    int widtht_;    //width of the grid of cells
    std::vector<std::vector<Cell*>> cells_;//cells,might need to be Qobject
};

#endif // LIFEGAME_H

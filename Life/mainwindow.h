#ifndef LIFEWINDOW_H
#define LIFEWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include <QGraphicsScene>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update_speed_label(int speed);
    void update_turn_label(int count);
    void set_game(Game* g) {g_ = g;};
    void set_height(int height) { height_ = height;};
    void set_width(int width) { width_ = width;};
    void set_color(QColor c) {c_ = c;};
    Game* get_game() {return g_;};
    int get_width() {return width_;};
    int get_height() {return height_;};
    QColor get_color() {return c_;};
    void create_graph();
    void create_grid();
    void update_grid();
private slots:
    void on_step_button_clicked();
    void on_speed_slider_valueChanged(int value);

    void on_actionNew_Game_triggered();

    void on_actionChange_Color_triggered();

    void on_play_button_clicked();

    void on_pause_button_clicked();

//    void update_display();
    // receive coordinates for game construction
    void get_game_coordinates(int height, int width);
private:
    Ui::MainWindow *ui;
    Game* g_ = nullptr;
    QGraphicsScene *scene;
    int width_;
    int height_;
    QColor c_;

};
#endif // LIFEWINDOW_H

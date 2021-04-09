#ifndef LIFEWINDOW_H
#define LIFEWINDOW_H

#include <QMainWindow>
#include "dialog.h"

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
    void set_game(Game* g) {g_ = g;};
    Game* get_game() {return g_;};
private slots:
    void on_step_button_clicked();
    void on_speed_slider_valueChanged(int value);

    void on_actionNew_Game_triggered();

    void on_actionChange_Color_triggered();

    void on_play_button_clicked();

    void on_pause_button_clicked();
    // receive coordinates for game construction
    void get_game_coordinates(int height, int width);
private:
    Ui::MainWindow *ui;
    Game* g_ = nullptr;

};
#endif // LIFEWINDOW_H

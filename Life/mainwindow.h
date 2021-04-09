#ifndef LIFEWINDOW_H
#define LIFEWINDOW_H

#include <QMainWindow>
#include "lifegame.h"
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

private slots:
    void on_step_button_clicked();
    void on_speed_slider_valueChanged(int value);

    void on_actionNew_Game_triggered();

    void on_actionChange_Color_triggered();

    void on_play_button_clicked();

    void on_pause_button_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // LIFEWINDOW_H

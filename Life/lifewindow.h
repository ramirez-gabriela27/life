#ifndef LIFEWINDOW_H
#define LIFEWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
#endif // LIFEWINDOW_H
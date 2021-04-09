#ifndef DIALOG_H
#define DIALOG_H
#include "lifegame.h"
#include <QDialog>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void set_height(int height) {height_input = height;};
    void set_width(int width) {width_input = width;};

    int get_height(){return height_input;};
    int get_width() {return width_input;};

signals:
    void send_coordinates(int height, int width);


private slots:
    // When user is done filling out text box
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    int height_input;
    int width_input;

};

#endif // DIALOG_H

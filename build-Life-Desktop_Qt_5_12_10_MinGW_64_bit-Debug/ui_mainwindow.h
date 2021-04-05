/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *step_button;
    QPushButton *play_button;
    QPushButton *pause_button;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *faster_label;
    QSlider *speed_slider;
    QLabel *slower_label;
    QLabel *speed_label;
    QGraphicsView *graph_view;
    QGraphicsView *grid_view;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *turn_label;
    QLabel *population_label;
    QMenuBar *menubar;
    QMenu *File_button;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 450, 791, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        step_button = new QPushButton(horizontalLayoutWidget);
        step_button->setObjectName(QString::fromUtf8("step_button"));

        horizontalLayout->addWidget(step_button);

        play_button = new QPushButton(horizontalLayoutWidget);
        play_button->setObjectName(QString::fromUtf8("play_button"));

        horizontalLayout->addWidget(play_button);

        pause_button = new QPushButton(horizontalLayoutWidget);
        pause_button->setObjectName(QString::fromUtf8("pause_button"));

        horizontalLayout->addWidget(pause_button);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        faster_label = new QLabel(horizontalLayoutWidget);
        faster_label->setObjectName(QString::fromUtf8("faster_label"));

        horizontalLayout_2->addWidget(faster_label);

        speed_slider = new QSlider(horizontalLayoutWidget);
        speed_slider->setObjectName(QString::fromUtf8("speed_slider"));
        speed_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(speed_slider);

        slower_label = new QLabel(horizontalLayoutWidget);
        slower_label->setObjectName(QString::fromUtf8("slower_label"));

        horizontalLayout_2->addWidget(slower_label);


        verticalLayout->addLayout(horizontalLayout_2);

        speed_label = new QLabel(horizontalLayoutWidget);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));

        verticalLayout->addWidget(speed_label);


        horizontalLayout->addLayout(verticalLayout);

        graph_view = new QGraphicsView(centralwidget);
        graph_view->setObjectName(QString::fromUtf8("graph_view"));
        graph_view->setGeometry(QRect(0, 350, 791, 101));
        grid_view = new QGraphicsView(centralwidget);
        grid_view->setObjectName(QString::fromUtf8("grid_view"));
        grid_view->setGeometry(QRect(0, 80, 791, 271));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 10, 791, 61));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        turn_label = new QLabel(verticalLayoutWidget_2);
        turn_label->setObjectName(QString::fromUtf8("turn_label"));

        verticalLayout_3->addWidget(turn_label);

        population_label = new QLabel(verticalLayoutWidget_2);
        population_label->setObjectName(QString::fromUtf8("population_label"));

        verticalLayout_3->addWidget(population_label);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        File_button = new QMenu(menubar);
        File_button->setObjectName(QString::fromUtf8("File_button"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(File_button->menuAction());
        File_button->addAction(actionNew_Game);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", nullptr));
        step_button->setText(QApplication::translate("MainWindow", "Step", nullptr));
        play_button->setText(QApplication::translate("MainWindow", "Play", nullptr));
        pause_button->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        faster_label->setText(QApplication::translate("MainWindow", "Slower", nullptr));
        slower_label->setText(QApplication::translate("MainWindow", "Faster", nullptr));
        speed_label->setText(QApplication::translate("MainWindow", "Speed: 0", nullptr));
        turn_label->setText(QApplication::translate("MainWindow", "Turn: 0", nullptr));
        population_label->setText(QApplication::translate("MainWindow", "Population: 0 (0%)", nullptr));
        File_button->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

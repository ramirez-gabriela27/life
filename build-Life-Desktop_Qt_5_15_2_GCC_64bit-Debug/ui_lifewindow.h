/********************************************************************************
** Form generated from reading UI file 'lifewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIFEWINDOW_H
#define UI_LIFEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Step;
    QPushButton *Play;
    QPushButton *Pause;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Faster;
    QSlider *SpeedSlider;
    QLabel *Slower;
    QLabel *speedLabel;
    QMenuBar *menubar;
    QMenu *menuLife;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 420, 791, 131));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Step = new QPushButton(horizontalLayoutWidget);
        Step->setObjectName(QString::fromUtf8("Step"));

        horizontalLayout->addWidget(Step);

        Play = new QPushButton(horizontalLayoutWidget);
        Play->setObjectName(QString::fromUtf8("Play"));

        horizontalLayout->addWidget(Play);

        Pause = new QPushButton(horizontalLayoutWidget);
        Pause->setObjectName(QString::fromUtf8("Pause"));

        horizontalLayout->addWidget(Pause);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Faster = new QLabel(horizontalLayoutWidget);
        Faster->setObjectName(QString::fromUtf8("Faster"));

        horizontalLayout_2->addWidget(Faster);

        SpeedSlider = new QSlider(horizontalLayoutWidget);
        SpeedSlider->setObjectName(QString::fromUtf8("SpeedSlider"));
        SpeedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(SpeedSlider);

        Slower = new QLabel(horizontalLayoutWidget);
        Slower->setObjectName(QString::fromUtf8("Slower"));

        horizontalLayout_2->addWidget(Slower);


        verticalLayout->addLayout(horizontalLayout_2);

        speedLabel = new QLabel(horizontalLayoutWidget);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));

        verticalLayout->addWidget(speedLabel);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuLife = new QMenu(menubar);
        menuLife->setObjectName(QString::fromUtf8("menuLife"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuLife->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Step->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        Faster->setText(QCoreApplication::translate("MainWindow", "Slower", nullptr));
        Slower->setText(QCoreApplication::translate("MainWindow", "Faster", nullptr));
        speedLabel->setText(QCoreApplication::translate("MainWindow", "Speed: 0.000", nullptr));
        menuLife->setTitle(QCoreApplication::translate("MainWindow", "Life", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIFEWINDOW_H

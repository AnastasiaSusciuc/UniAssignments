//
// Created by octat on 6/18/2021.
//

#ifndef SECONDARY_GUI_H
#define SECONDARY_GUI_H
#pragma once
#include <qwidget.h>
#include "Programmer.h"
#include "Service.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "ProgWindow.h"
#include "StatisticWindow.h"

class GUI: public QWidget {
Q_OBJECT
private:
    Service &ctrl;

public:
    GUI(Service &ctrl, QWidget *parent = 0) : ctrl{ctrl}{ progs=this->ctrl.get_all_prog();};


    void initGUI();

private:
    std::vector<Programmer> progs;
    std::vector<ProgWindow*> windowList;

    StatisticWindow *statisticWindow;

    QListWidget *movieList;
    QListWidget *movieWatchList;

public:
    void update_all();
};
#endif //SECONDARY_GUI_H

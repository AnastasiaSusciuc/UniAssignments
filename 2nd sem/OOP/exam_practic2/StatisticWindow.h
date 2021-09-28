//
// Created by octat on 6/18/2021.
//

#ifndef SECONDARY_STATISTICWINDOW_H
#define SECONDARY_STATISTICWINDOW_H
#include <QMainWindow>
#include "Service.h"
#include <QLabel>

class StatisticWindow : public QMainWindow {
    Service &service;
public:
    StatisticWindow(Service &service) : service{service}{ this->init();};
    vector<QLabel*> labels;
    void init();
    void update();
};


#endif //SECONDARY_STATISTICWINDOW_H

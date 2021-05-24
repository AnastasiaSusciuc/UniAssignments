//
// Created by susci on 5/24/2021.
//

#ifndef UNTITLED1_GUI_H
#define UNTITLED1_GUI_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include "Service.h"
#include <iostream>
#include <QSlider>
#include <QCheckBox>

class GUI : public QWidget {
Q_OBJECT
private:
    Service& srv;
    QListWidget* time_list;
    QSlider* slider;
    QPushButton* reset;
    QCheckBox* check[100];

public:
    GUI(Service& _srv): srv{_srv}{
        this->draw_gui();
        this->populate_products();
//        this->connect();
    };

    void draw_gui();
    void populate_products();


    void reset_all();

public slots:
    void show_filter_1(int value);
    void map(int cnt);

};


#endif //UNTITLED1_GUI_H

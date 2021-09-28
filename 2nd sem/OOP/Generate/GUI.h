//
// Created by Tudor Tise on 23/05/2021.
//

#ifndef GENERATE_GUI_H
#define GENERATE_GUI_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include "Service.h"

class GUI : public QWidget{
private:
    Service& srv;

    QListWidget* products_list;
    QListWidget* filtered_list;

    QPushButton* delete_product_button;
    QPushButton* filter_button;

    QLineEdit* text_box_filter_category;
    QLineEdit* text_box_delete_by_name;
public:
    GUI(Service& _srv): srv{_srv}{
        this->draw_gui();
        this->populate_products();
        this->connect();
    };

    void draw_gui();
    void populate_products();

    int get_selected();

    void connect();

    void delete_gui();

    void filter_gui();

};


#endif //GENERATE_GUI_H

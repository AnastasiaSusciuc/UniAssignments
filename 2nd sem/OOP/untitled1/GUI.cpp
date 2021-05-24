//
// Created by susci on 5/24/2021.
//

#include "GUI.h"

void GUI::draw_gui() {
    QLabel* label = new QLabel{"Time Intervals List"};

    QWidget* main = new QWidget;

    QVBoxLayout* layoutV = new QVBoxLayout{main};

    this->time_list = new QListWidget();

    this->slider = new QSlider();
    this->slider->setTickInterval(100);

    QObject::connect(this->slider, SIGNAL(valueChanged(int)), this, SLOT(show_filter_1(int)));

    this->reset = new QPushButton{"Reset"};
    QObject::connect(this->reset, &QPushButton::clicked, this, &GUI::reset_all);

//    check = new QCheckBox;

    std::vector < std::string> all_descriptions = srv.get_descriptions();




    layoutV->addWidget(label,0, Qt::AlignCenter);
    layoutV->addWidget(this->time_list);
    layoutV->addWidget(this->slider);

    int cnt = 0;
    for (auto d:all_descriptions)
    {
        check[cnt++] = new QCheckBox(QString::fromLocal8Bit(d.c_str()));
        layoutV->addWidget(check[cnt-1]);
        QObject::connect(check[cnt-1], SIGNAL(toggled(bool)), this, SLOT(map(cnt)));
        // QObject::connect(this->slider, SIGNAL(valueChanged(int)), this, SLOT(show_filter_1(int)));
    }
    layoutV->addWidget(this->reset);

    QFont font_filter = QFont{};
    font_filter.setBold(true);


    main->setLayout(layoutV);
    main->show();
}

void GUI::populate_products() {
    this->time_list->clear();

    std::vector<TimeInterval> products = this->srv.get_products_service();

    for (auto p: products){
        this->time_list->addItem(QString::fromStdString(p.toString()));
    }
}

void GUI::show_filter_1(int value) {
//    std::cout << "HERE!";
//    std::cout << value << "<3 ";
    std::vector<TimeInterval> filtered = this->srv.get_filtered_list(value);
    this->time_list->clear();

    for (auto p: filtered){
        this->time_list->addItem(QString::fromStdString(p.toString()));
    }

}

void GUI::reset_all() {
    this->populate_products();
    slider->setTickPosition(QSlider::TicksBelow);
}

void GUI::map(int cnt) {
    std::cout << cnt << '\n';
}

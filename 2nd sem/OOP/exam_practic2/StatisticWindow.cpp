//
// Created by octat on 6/18/2021.
//

#include "StatisticWindow.h"
#include <QVBoxLayout>
#include <QPainter>

void StatisticWindow::init() {
    this->resize(500,500);
    this->setWindowTitle(QString::fromStdString("Statistics"));
    for(auto p:service.get_all_prog())
    {
        auto *label = new QLabel{QString(p.getName().c_str())};
        QPixmap pixmap(100,100);
        pixmap.fill(QColor("transparent"));

        QPainter painter(&pixmap);
        if(service.get_nr_not_revised(p)==0)
            painter.setBrush(QBrush(Qt::blue));
        else
            painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(10, 10, service.get_nr_already_revised(p)*50+10, service.get_nr_already_revised(p)*50+10);

        label->setPixmap(pixmap);
        labels.push_back(label);

    }

    QWidget *central_widget = new QWidget;
    QVBoxLayout *vboxlayout = new QVBoxLayout{};

    for(auto l: labels)
        vboxlayout->addWidget(l);
    central_widget->setLayout(vboxlayout);

    this->setCentralWidget(central_widget);
}

void StatisticWindow::update() {
    for(auto p:service.get_all_prog())
    {
        auto *label = new QLabel{QString(p.getName().c_str())};
        QPixmap pixmap(100,100);
        pixmap.fill(QColor("transparent"));

        QPainter painter(&pixmap);
        if(service.get_nr_not_revised(p)==0)
            painter.setBrush(QBrush(Qt::blue));
        else
            painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(10, 10, service.get_nr_already_revised(p)*50+10, service.get_nr_already_revised(p)*50+10);

        label->setPixmap(pixmap);
        labels.push_back(label);

    }
}

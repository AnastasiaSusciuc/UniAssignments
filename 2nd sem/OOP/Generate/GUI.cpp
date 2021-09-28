//
// Created by Tudor Tise on 23/05/2021.
//

#include <QMessageBox>
#include "GUI.h"

void GUI::draw_gui() {
    QLabel* label = new QLabel{"SHOPPING LIST"};

    QWidget* main = new QWidget;

    QVBoxLayout* layoutV = new QVBoxLayout{main};

    this->products_list = new QListWidget();

    layoutV->addWidget(label,0, Qt::AlignCenter);
    layoutV->addWidget(this->products_list);

    this->text_box_filter_category = new QLineEdit{};
    this->text_box_delete_by_name = new QLineEdit{};

    QLabel* label_text_box = new QLabel{"Category"};
    QLabel* label_text_delete = new QLabel{"Name"};

    label_text_delete->setBuddy(this->text_box_delete_by_name);

    label_text_box->setBuddy(this->text_box_filter_category);

    this->delete_product_button = new QPushButton{"Delete"};

    layoutV->addWidget(label_text_delete);
    layoutV->addWidget(this->text_box_delete_by_name);
    layoutV->addWidget(this->delete_product_button);

    layoutV->addWidget(label_text_box);
    layoutV->addWidget(this->text_box_filter_category);

    QFont font_filter = QFont{};
    font_filter.setBold(true);

    this->filtered_list = new QListWidget();
    this->filtered_list->setFont(font_filter);

    this->filter_button = new QPushButton{"Filter"};

    layoutV->addWidget(this->filter_button);
    layoutV->addWidget(this->filtered_list);

    main->setLayout(layoutV);
    main->show();
}

void GUI::populate_products() {
    this->products_list->clear();

    std::vector<Product> products = this->srv.get_products_service();

    //sort blanao
    sort( products.begin( ), products.end( ), [ ]( const Product& lhs, const Product& rhs )
    {
        return lhs.getName() < rhs.getName();
    });

    for (auto p: products){
        this->products_list->addItem(QString::fromStdString(p.toString()));
    }
}

int GUI::get_selected() {
    QModelIndexList index = this->products_list->selectionModel()->selectedIndexes();

    if (index.empty()){
        this->text_box_delete_by_name->clear();
        return -1;
    }

    int selectedIndex = index.at(0).row();
    return selectedIndex;

}

void GUI::connect() {
    QObject::connect(this->delete_product_button, &QPushButton::clicked, this, &GUI::delete_gui);
    QObject::connect(this->filter_button, &QPushButton::clicked, this, &GUI::filter_gui);
    QObject::connect(this->products_list, &QListWidget::itemSelectionChanged, [this]() {

        int selectedIndex = this->get_selected();

        if (selectedIndex < 0){
            return;
        }

        Product p  = this->srv.get_product_by_pos(selectedIndex);
        this->text_box_delete_by_name->setText(QString::fromStdString(p.getName()));

    });
}

void GUI::delete_gui() {
    if (this->text_box_delete_by_name->text().isEmpty()){
        QMessageBox::information(this, "Error!", QString::fromStdString("No name provided"));
    } else {
        this->srv.delete_product_service(this->text_box_delete_by_name->text().toStdString());
        this->populate_products();
    }
}

void GUI::filter_gui() {
    if (this->text_box_filter_category->text().isEmpty()){
        QMessageBox::information(this, "Error!", QString::fromStdString("No category provided"));
    } else {
        std::vector<Product> filtered = this->srv.get_filtered_list(this->text_box_filter_category->text().toStdString());
        this->filtered_list->clear();

        for (auto p: filtered){
            this->filtered_list->addItem(QString::fromStdString(p.toString()));
        }
    }
}
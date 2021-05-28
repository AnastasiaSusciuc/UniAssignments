//
// Created by susci on 5/11/2021.
//


#include "QtMenu.h"

QtMenu::QtMenu(AdminService &adminServ, UserService &userServ): adminService{adminServ}, userService{userServ} {
    this->setWindowTitle("Choose mode");
    this->resize(500, 500);

    auto vLayout = new QVBoxLayout();
    this->setLayout(vLayout);

    auto adminButton = new QPushButton("Admin");
    QObject::connect(adminButton, &QPushButton::clicked, this, &QtMenu::showAdmin);
    vLayout->addWidget(adminButton);

    auto userButton = new QPushButton("User");
    QObject::connect(userButton, &QPushButton::clicked, this, &QtMenu::showUser);
    vLayout->addWidget(userButton);
}

void QtMenu::showAdmin() {

    auto admin = new AdminGUI(this->adminService);
    admin->show();
}

void QtMenu::showUser() {
    auto user = new UserGUI(this->adminService, this->userService);
    user->show();
}

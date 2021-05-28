//
// Created by susci on 5/11/2021.
//

#ifndef UNTITLED_QTMENU_H
#define UNTITLED_QTMENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
//#include <QtCharts/QtChart>
#include "../Service/AdminService.h"
#include "../Service/UserService.h"
#include "AdminGUI.h"
#include "UserGUI.h"

class QtMenu: public QWidget {
private:
    AdminService& adminService;
    UserService& userService;
public:
    explicit QtMenu(AdminService& adminService, UserService& userService);
    void showAdmin();
    void showUser();
};


#endif //UNTITLED_QTMENU_H

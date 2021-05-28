//
// Created by susci on 5/11/2021.
//

#ifndef UNTITLED_USERGUI_H
#define UNTITLED_USERGUI_H

#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QListWidget>
#include <QMessageBox>
#include <QDebug>
#include <Windows.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>
#include "../Service/UserService.h"
#include "../Service/AdminService.h"

class UserGUI : public QWidget {
private:
    AdminService &adminService;
    UserService& userService;
    QListWidget* watchListWidget;
    QLineEdit* substringPresenter;
    QLineEdit* deleteLink;

public:
    UserGUI(AdminService& adminServ, UserService &userServ);
    void mainWindow();
    void presentTutorials();
    void populateWatchList();
    void deleteTutorial();
    ~UserGUI() override = default;
};


#endif //UNTITLED_USERGUI_H

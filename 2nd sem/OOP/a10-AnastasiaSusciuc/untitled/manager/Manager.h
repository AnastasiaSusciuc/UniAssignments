//
// Created by susci on 5/12/2021.
//

#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H
#include "../Service/AdminService.h"
#include "../Service/UserService.h"
#include "../Repository/CSVWatchList.h"
#include "../Repository/HTMLWatchList.h"
#include "../UI/UI.h"
#include "../GUI/PersistenceGUI.h"
#include <QMessageBox>
#include <QDebug>
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

class Manager {

public:
    static void run_ui();
    void run_gui();
};


#endif //UNTITLED_MANAGER_H

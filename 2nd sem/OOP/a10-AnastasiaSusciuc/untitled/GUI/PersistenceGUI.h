//
// Created by susci on 5/12/2021.
//

#ifndef UNTITLED_PERSISTENCEGUI_H
#define UNTITLED_PERSISTENCEGUI_H
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "../Service/AdminService.h"
#include "../Service/UserService.h"
#include "../Repository/CSVWatchList.h"
#include "../Repository/HTMLWatchList.h"
#include "QtMenu.h"

class PersistenceGUI: public QWidget {

public:
    PersistenceGUI();
    void CSV_persistence();
    void HTML_persistence();
};


#endif //UNTITLED_PERSISTENCEGUI_H

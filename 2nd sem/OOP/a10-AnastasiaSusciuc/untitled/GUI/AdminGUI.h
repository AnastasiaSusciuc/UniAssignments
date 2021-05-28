//
// Created by susci on 5/11/2021.
//

#ifndef UNTITLED_ADMINGUI_H
#define UNTITLED_ADMINGUI_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QApplication>
#include <QMessageBox>
#include <QListWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <string>
#include "../Service/AdminService.h"
#include "ChartGUI.h"


class AdminGUI : public QWidget{
private:
    AdminService& adminService;
    QListWidget* tutorialListWidget;
    QLineEdit* title;
    QLineEdit* presenter;
    QLineEdit* minutes;
    QLineEdit* seconds;
    QLineEdit* likes;
    QLineEdit* link;
    QPushButton* undo;
    QPushButton* redo;

public:
    AdminGUI(AdminService& adminService);
    void mainWindow();
    void populateTutorialsList();
    void connectSignalsAndSlots();
    ~AdminGUI() override = default;
    void addTutorial();
    void deleteTutorial();
    void updateTutorial();
    void clearLineEdits();
    void showChart();
    void undo_function();
    void redo_function();
    int get_selected();
};


#endif //UNTITLED_ADMINGUI_H

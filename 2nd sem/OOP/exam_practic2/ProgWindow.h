//
// Created by octat on 6/18/2021.
//

#ifndef SECONDARY_PROGWINDOW_H
#define SECONDARY_PROGWINDOW_H
#pragma once
#include "SourceFile.h"
#include <QAbstractTableModel>
#include <QWindow>
#include <QMainWindow>
#include "Programmer.h"
#include "Service.h"
#include <QLabel>
#include "SourcefileTableModel.h"
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <utility>
//#include "GUI.h"
#include "StatisticWindow.h"

class ProgWindow : public QMainWindow
{
    Q_OBJECT
private:
    Programmer &prog;
    Service &ctrl;
    //GUI *gui;
    //QWidget *parent;
    QWidget *parent;
    std::vector<ProgWindow*> &window;
    StatisticWindow *statisticWindow;

public:
    ProgWindow(Programmer &prog, Service& service, std::vector<ProgWindow*> &window, StatisticWindow *statisticWindow1) : prog{prog}, ctrl{service}, window{window}, statisticWindow{statisticWindow1} { this->init_progwindow();};

private:
    QLabel *label;
    QTableView *table;

    QLabel *already_revised;
    QLineEdit *already_revised_edit;
    QLabel *left_to_revise;
    QLineEdit* left_to_revise_edit;

    QLineEdit* added_file_edit;
    QLabel* added_file_label;

    QPushButton* add_button;
    QPushButton* revise;

    QLineEdit* errors;
    SourcefileTableModel *tablemodel;

    void init_progwindow();

    void connect();
    void connectAdd();

    void update_table();
    void update_table_no_extra();
    void pressed();
};



#endif //SECONDARY_PROGWINDOW_H

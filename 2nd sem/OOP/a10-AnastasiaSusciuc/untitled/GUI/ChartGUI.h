//
// Created by susci on 5/15/2021.
//

#ifndef UNTITLED_CHARTGUI_H
#define UNTITLED_CHARTGUI_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QApplication>
#include <QListWidget>
#include <QLineEdit>
#include <QFormLayout>
#include "../Service/AdminService.h"

#include <QApplication>

// The main window to which you add toolbars,
// menubars, widgets and status bar
#include <QtWidgets/QMainWindow>

// Widget used to display charts
#include <QtCharts>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <map>

class ChartGUI : public QWidget{
private:
    AdminService& adminService;
public:
    explicit ChartGUI(AdminService& adminService);
    void mainWindow();
    std::map <std::string, int> get_every_presenter_number_of_tutorials();

};


#endif //UNTITLED_CHARTGUI_H

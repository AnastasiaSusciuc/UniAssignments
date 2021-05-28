#include "Tests/tests.h"
#include "Service/AdminService.h"
#include "Service/UserService.h"
#include "Repository/CSVWatchList.h"
#include "Repository/HTMLWatchList.h"
#include "GUI/AdminGUI.h"
#include "GUI/QtMenu.h"
#include "UI/UI.h"
#include <QApplication>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include "manager/Manager.h"

int main(int argc, char *argv[])
{
    Tests::run_all_tests();

    QApplication a{ argc, argv };
    a.setFont(QFont("San Francisco"));

    QFile stylesheet("C:/Users/susci/Desktop/untitled/GUI/nice_stylesheets.qss");

    stylesheet.open(QFile::ReadOnly);
    QString style = QLatin1String(stylesheet.readAll());
    a.setStyleSheet(style);


    FileRepository all_tutorials_repository("../Files/input.txt");
    WatchListRepository* user_repo;
    user_repo = new CSVWatchList("../Files/watchlist.csv", "../Files/watchlist.txt");
    AdminService admin_service = { all_tutorials_repository };
    UserService user_service = { user_repo };
    auto menu = new QtMenu(admin_service, user_service);
    menu->show();

    return a.exec();
}
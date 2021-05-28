//
// Created by susci on 5/12/2021.
//

#include "PersistenceGUI.h"


PersistenceGUI::PersistenceGUI() {

    this->setWindowTitle("Choose persistence for watchlist:");
    this->resize(   1000, 1000);
    std::cout << "1\n";

    auto vLayout = new QVBoxLayout();
    this->setLayout(vLayout);
    std::cout << "2\n";

    auto adminButton = new QPushButton("CSV");
    QObject::connect(adminButton, &QPushButton::clicked, this, &PersistenceGUI::CSV_persistence);
    vLayout->addWidget(adminButton);

    std::cout << "3\n";
    auto userButton = new QPushButton("HTML");
    QObject::connect(userButton, &QPushButton::clicked, this, &PersistenceGUI::HTML_persistence);
    vLayout->addWidget(userButton);

    std::cout << "4\n";
}

void PersistenceGUI::CSV_persistence() {
    std::cout << "csv\n";

     FileRepository all_tutorials_repository("../Files/input.txt");

    // std::cout << "CSV pers " << &all_tutorials_repository << '\n';

    WatchListRepository* user_repo;
    user_repo = new CSVWatchList("../Files/watchlist.csv", "../Files/watchlist.txt");

    AdminService admin_service = { all_tutorials_repository };

    std::cout << "MOR cu zile " << &all_tutorials_repository << " " << &admin_service << '\n';

    UserService user_service = { user_repo };

    auto menu = new QtMenu(admin_service, user_service);
    menu->show();
}

void PersistenceGUI::HTML_persistence() {
    std::cout << "html\n";
    FileRepository all_tutorials_repository("../Files/input.txt");
    WatchListRepository* user_repo;
    user_repo = new HTMLWatchList("../Files/watchlist.html", "../Files/watchlist.txt");
    AdminService admin_service = { all_tutorials_repository };
    UserService user_service = { user_repo };
    auto menu = new QtMenu(admin_service, user_service);
    menu->show();
}
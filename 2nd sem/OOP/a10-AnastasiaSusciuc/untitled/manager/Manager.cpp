//
// Created by susci on 5/12/2021.
//

#include "Manager.h"

void Manager::run_ui() {
    std::cout << "Choose persistence mode (CSV / HTML): ";
    std::string persistence;
    std::cin >> persistence;

    FileRepository all_tutorials_repository("../Files/input.txt");

    WatchListRepository* user_repo;

    if (persistence == "HTML")
    {
        user_repo = new HTMLWatchList("../Files/watchlist.html", "../Files/watchlist.txt");
    }
    else if (persistence == "CSV")
    {
        user_repo = new CSVWatchList("../Files/watchlist.csv", "../Files/watchlist.txt");
    }
    else
    {
        std::cout << "Invalid persistence! Stopping the app..";
        return;
    }

    AdminService admin_service = { all_tutorials_repository };
    UserService user_service = { user_repo };

    UITutorial ui = { admin_service, user_service };
    ui.run();

}

void Manager::run_gui() {

//    auto persistenceGui = new PersistenceGUI();
//    // PersistenceGUI persistenceGui;
//    persistenceGui->show();
}

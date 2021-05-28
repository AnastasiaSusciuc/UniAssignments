//
// Created by susci on 3/23/2021.
//

#include "UI.h"
#include <Windows.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>
#include <bits/stdc++.h>

UITutorial::UITutorial(AdminService &adminService, UserService &userService) :adminService{adminService}, userService {userService} {
}

UITutorial::~UITutorial() = default;

void UITutorial::run()
{
    std::string mode;
    while(true) {
        std::cout << "Choose mode (a for 'Administrator mode' / u for 'User mode' / e for 'exit'): ";
        std::cin >> mode;
        if (mode == "a")
            run_administrator_mode();
        else if (mode == "u")
            run_user_mode();
        else if (mode == "e")
            break;
        else
            std::cout << "Invalid mode!\n";
    }
}

void UITutorial::run_user_mode() {
    std::string mode;
    while(true) {

        std::cout << "Select your option:\n";
        std::cout << "s - see the tutorials having a given presenter\n";
        std::cout << "a - see all tutorials from the watchlist\n";
        std::cout << "d - delete a tutorial from the watchlist\n";
        std::cout << "e - exit user mode\n";
        std::cout << "p - show in persistent memory the watchlist\n";
        std::cin >> mode;
        if (mode == "s")
            ui_see_tutorials_by_presenter();
        else if (mode == "a")
            ui_see_watch_list();
        else if (mode == "d")
            ui_delete_tutorial_from_watch_list();
        else if (mode == "e")
            break;
        else if (mode == "p")
            ui_show_watchlist();
        else
            std::cout << "Invalid mode!\n";
    }
}

void UITutorial::ui_admin_add_tutorial() {
    std::string input;
    std::string title, presenter, link;
    int likes;
    std::pair <int, int> duration;

    std::cout << "Insert the title of the tutorial:";
    std::cin >> title;

    std::cout << "Insert the presenter of the tutorial:";
    std::cin >> presenter;

    std::cout << "Insert the minutes the tutorial lasts:";
    std::cin >> input;

    try {
        duration.first = stoi(input);
    } catch(std::exception &err) {
        std::cout << "The number of minutes should be an integer\n";
        return;
    }

    std::cout << "Insert the seconds the tutorial lasts:";
    std::cin >> input;
    try {
        duration.second = stoi(input);
    } catch(std::exception &err) {
        std::cout << "The number of seconds should be an integer between 0 and 59\n";
        return;
    }

    std::cout << "Insert the number of likes of the tutorial:";
    std::cin >> input;

    try {
        likes = stoi(input);
    } catch(std::exception &err) {
        std::cout << "The number of likes should be an integer\n";
        return;
    }

    std::cout << "Insert the link of the tutorial:";
    std::cin >> link;

    try {
        adminService.add_tutorial_admin_service(title, presenter, duration, likes, link);
        std::cout << "Tutorial added successfully!\n";
    } catch (RepositoryException& repositoryException) {
        std::cout << repositoryException.what();
    } catch (ValidationException& validationException) {
        std::cout << validationException.what();
    }
}

void UITutorial::ui_admin_remove_tutorial() {
    std::string link;
    std::cout << "Insert the link of the tutorial to be removed:";
    std::cin >> link;

    try {
        adminService.remove_tutorial_admin_service(link);
        std::cout << "Tutorial removed successfully!\n";
    } catch(RepositoryException& repositoryException) {
        std::cout << repositoryException.what();
    }

}

void UITutorial::ui_admin_update_tutorial() {
    std::string old_link, title, presenter, input;
    int likes;
    std::pair <int, int> duration;

    std::cout << "Insert the link of the tutorial to be updated:";
    std::cin >> old_link;

    std::cout << "Insert the new title of the tutorial:";
    std::cin >> title;

    std::cout << "Insert the new presenter of the tutorial:";
    std::cin >> presenter;

    std::cout << "Insert the new minutes the tutorial lasts:";
    std::cin >> input;

    try {
        duration.first = stoi(input);
    } catch(std::exception &err) {
        std::cout << "The number of minutes should be an integer\n";
        return;
    }

    std::cout << "Insert the new seconds the tutorial lasts:";
    std::cin >> input;

    try {
        duration.second = stoi(input);
    } catch(std::exception &err) {
        std::cout << "The number of seconds should be an integer between 0 and 59\n";
        return;
    }

    if (duration.second < 0 || duration.second >= 60) {
        std::cout << "The number of seconds should be an integer between 0 and 59\n";
        return;
    }

    std::cout << "Insert the new number of likes of the tutorial:";
    std::cin >> input;
    try {
        likes = stoi(input);
    } catch(std::exception &err) {
        std::cout << "The number of likes should be an integer\n";
        return;
    }

    try {
        adminService.update_tutorial_admin_service(old_link, title, presenter, duration, likes);
        std::cout << "Tutorial updated successfully!\n";
    } catch(RepositoryException& repositoryException) {
        std::cout << repositoryException.what();
    }
}

void UITutorial::ui_print_all_tutorials_in_repo() {
    std::vector <Tutorial> all_tutorials = adminService.all_tutorials_service();
    int counter = 0;
    for (auto & it : all_tutorials) {
        std::cout << "Tutorial no. " << ++counter << '\n';
        std::cout << "\tTitle: " << it.get_title() << '\n';
        std::cout << "\tPresenter: " << it.get_presenter() << '\n';
        std::cout << "\tDuration: " << it.get_duration().first << " minutes " << it.get_duration().second << " seconds\n";
        std::cout << "\tNo. likes: " << it.get_number_of_likes() << '\n';
        std::cout << "\tLink: " << it.get_link() << '\n';
    }
}

void UITutorial::run_administrator_mode() {

    std::string option;

    while(true) {

        std::cout << "Choose an option: \n";
        std::cout << "\t a - to add a tutorial\n";
        std::cout << "\t r - to remove a tutorial\n";
        std::cout << "\t u - to update a tutorial\n";
        std::cout << "\t all - to print all tutorial in the repository\n";
        std::cout << "\t e - to exit 'Admin mode'\n";

        std::cin >> option;
        if (option == "a")
            ui_admin_add_tutorial();
        else if (option == "r")
            ui_admin_remove_tutorial();
        else if (option == "u")
            ui_admin_update_tutorial();
        else if (option == "e")
            break;
        else if (option == "all")
            ui_print_all_tutorials_in_repo();
        else
            std::cout << "Invalid option\n";
    }
}

void UITutorial::add_items_by_default() {

    adminService.add_tutorial_admin_service("Afterglow", "Wilkinson", std::make_pair(2, 51), 438000, "https://www.youtube.com/watch?v=I9QGpHScGug");
    adminService.add_tutorial_admin_service("Waiting All Night", "Rudimental", std::make_pair(5, 15), 981000, "https://www.youtube.com/watch?v=M97vR2V4vTs");
    adminService.add_tutorial_admin_service("Nobody to love", "Sigma", std::make_pair(4, 02), 845000, "https://www.youtube.com/watch?v=KD5fLb-WgBU");
    adminService.add_tutorial_admin_service("Kill the silence", "The Prototypes", std::make_pair(4, 04), 13000, "https://www.youtube.com/watch?v=2YLtT_evCNg");
    adminService.add_tutorial_admin_service("Sweet lies", "Wilkinson", std::make_pair(3, 51), 85000, "https://www.youtube.com/watch?v=OYzCe1T_Gpg&list=RDOYzCe1T_Gpg&start_radio=1");
    adminService.add_tutorial_admin_service("Hold On", "Rusko", std::make_pair(5, 51), 41000, "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    adminService.add_tutorial_admin_service("All for you", "Wilkinson", std::make_pair(3, 28), 104000, "https://www.youtube.com/watch?v=kU15AzJI648");
    adminService.add_tutorial_admin_service("Would I Lie To You?", "Charles & Eddie", std::make_pair(3, 11), 562000, "https://www.youtube.com/watch?v=dgh4T3VuXCc");
    adminService.add_tutorial_admin_service("Love the way you lie", "Eminem feat. Rihanna", std::make_pair(4, 26), 10000000, "https://www.youtube.com/watch?v=uelHwf8o7_U");
    adminService.add_tutorial_admin_service("One more night", "Maroon 5", std::make_pair(3, 43), 3600000, "https://www.youtube.com/watch?v=fwK7ggA3-bU");
}

void UITutorial::ui_see_tutorials_by_presenter() {
    std::string presenter, answer, cont;
    std::cout << "Insert a substring to filter the tutorials with respect to the presenter by:";
    std::string p2;
    std::cin >> presenter;

    // std::cout << "PRES " << presenter << '\n';
    std::vector <Tutorial> tutorials_by_presenter = adminService.tutorials_by_presenter_service(presenter);

    if (tutorials_by_presenter.size() == 0)
    {
        std::cout << "There are no such tutorials!\n";
        return;
    }

    while(true) {

        for (auto & it : tutorials_by_presenter) {
            const std::string& link = it.get_link();
            // ShellExecuteA(nullptr, nullptr, "chrome.exe", (it.get_link()).c_str(), nullptr, SW_SHOWMAXIMIZED);

            std::cout << it << '\n';

            std::cout << "Do you want to add this tutorial to the watchlist? y/n ";
            std::cin >> answer;
            if (answer == "y") {
                try {
                    userService.add_tutorial_watch_list_user_service(it);
                } catch (RepositoryException& repositoryException) {
                    std::cout << repositoryException.what();
                }
            }

            std::cout << "Do you want to see another tutorial? y/n";
            std::cin >> cont;
            if (cont == "n")
                break;
        }
        if (cont == "n")
            break;
    }
}

void UITutorial::ui_see_watch_list() {
    std::vector <Tutorial> watchlist = userService.all_tutorials_watch_list_service();

    for (auto & it : watchlist)
        std::cout << it << '\n';

}

void UITutorial::ui_delete_tutorial_from_watch_list() {
    std::string link;
    std::cout << "Insert the link of the tutorial to erase:";
    std::cin >> link;

    try{
        userService.remove_tutorial_watch_list_user_service(link);
        std::cout << "Tutorial deleted successfully from the watch list!\n";
    } catch(RepositoryException& repositoryException) {
        std::cout << repositoryException.what();
    }


    std::string answer;
    std::cout << "Did you like the tutorial? y/n";
    std::cin >> answer;

    if (answer == "y")
        adminService.increase_likes_tutorial_service(link);
}

void UITutorial::ui_show_watchlist() {
    std::string repo_type = userService.get_repo_type();
    // std::string file_name = userService.get_file_name();
    char file_name[50];
    std::stringstream(userService.get_file_name()) >> file_name;


    if(repo_type == "HTML") {
        try {
            ShellExecuteA(nullptr, nullptr,
                          // C:\Users\susci\Desktop\untitled\Files\watchlist.csv
                          "C:/Users/susci/Desktop/untitled/Files/watchlist.html",
                          (userService.get_file_name()).c_str(), nullptr, SW_SHOWMAXIMIZED);
            // ShellExecute(NULL, "open", file_name, NULL, NULL, SW_SHOW);
            std::cout << "E GHINI!\n";
        }
        catch (...) {
            std::cout << "HOPAAA!\n";
        }
    }
    else
    {
        try {
            ShellExecuteA(nullptr, nullptr,
                          "C:/Users/susci/Desktop/untitled/Files/watchlist.csv",
                          (userService.get_file_name()).c_str(), nullptr, SW_SHOWMAXIMIZED);
            // ShellExecute(NULL, "open", file_name, NULL, NULL, SW_SHOW);
            std::cout << "E GHINI!\n";
        }
        catch (...) {
            std::cout << "HOPAAA!\n";
        }

    }

//    std::cout << command << '\n';
//    system(command.c_str());
}

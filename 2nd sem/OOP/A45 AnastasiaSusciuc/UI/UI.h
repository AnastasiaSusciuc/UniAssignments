//
// Created by susci on 3/23/2021.
//

#ifndef OOP_UI_H
#define OOP_UI_H
#include "../Service/AdminService.h"
#include "../Service/UserService.h"
#include <iostream>

class UITutorial{
private:
    AdminService& adminService;
    UserService& userService;

public:
    UITutorial(AdminService& adminService, UserService& userService);
    ~UITutorial();
    void run();
    /*
     * description:  starts the application and switches between user and admin
     *
     * returns:      -
     * */
    void run_administrator_mode();
    /*
     * description:  runs the administrator mode, prints the menu
     *
     * returns:      -
     * */
    void run_user_mode();
    /*
     * description:  runs the user mode, prints the menu
     *
     * returns:      -
     * */
    void ui_admin_add_tutorial();
    /*
     * description:  reads input from the user, validates the input and passes the input to the admin service
     *
     * returns:      -
     * */
    void ui_admin_remove_tutorial();
    /*
     * description:  reads input from the user, validates the input and passes the input to the admin service
     *
     * returns:      -
     * */
    void ui_admin_update_tutorial();
    /*
     * description:  reads input from the user, validates the input and passes the input to the admin service
     *
     * returns:      -
     * */
    void ui_print_all_tutorials_in_repo();
    /*
     * description:  gets all the tutorials from the repo and prints them onto the console
     *
     * returns:      -
     * */
    void add_items_by_default();
    /*
     * description:  adds 10 tutorials by default in the repository of the tutorials
     *
     * returns:      -
     * */
    void ui_see_tutorials_by_presenter();
    /*
     * description:  prints only the tutorials that contain a given substring in the presenter
     *
     * returns:      -
     * */
    void ui_see_watch_list();
    /*
     * description:  prints all the tutorials that were added in the watchlist
     *
     * returns:      -
     * */
    void ui_delete_tutorial_from_watch_list();
    /*
     * description:  deletes a tutorial from the watchlist
     *
     * returns:      -
     * */
};

#endif //OOP_UI_H

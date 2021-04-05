//
// Created by susci on 3/20/2021.
//

#ifndef OOP_TESTS_H
#define OOP_TESTS_H
#pragma once
#include <cassert>

class Tests{

public:
    static void run_all_tests();

private:
    static void run_domain_tests();
    static void run_dynamic_array_tests();
    static void run_repository_tests();
    static void run_admin_service_tests();

    // -Dynamic Array
    static void create_dynamic_array_test();
    static void resize_dynamic_array_test();
    static void add_element_in_dynamic_array_test();
    static void search_element_in_dynamic_array_test();
    static void remove_element_in_dynamic_array_test();
    static void update_element_in_dynamic_array_test();

    // -Tutorial Entity
    static void create_tutorial_test();

    // -Repository
    static void run_admin_repository_tests();
    static void run_user_repository_tests();

    static void create_repository_test();
    static void add_tutorial_in_repository_test();
    static void remove_tutorial_from_repository_test();
    static void update_tutorial_from_repository_test();
    static void all_tutorials_from_repository_test();
    static void admin_increase_likes_in_repository_test();

    static void create_watchlist_repository_test();
    static void add_tutorial_in_watchlist_test();
    static void remove_tutorial_from_watchlist_test();
    static void all_tutorials_from_watchlist_test();
    static void get_tutorial_by_position_test();

    // -Service
    static void run_admin_service_test();
    static void run_user_service_test();

    static void add_tutorial_admin_service_test();
    static void remove_tutorial_admin_service_test();
    static void update_tutorial_admin_service_test();
    static void all_tutorials_service_test();
    static void tutorials_by_presenter_service_test();
    static void increase_likes_service_test();

    static void add_tutorial_user_service_test();
    static void remove_tutorial_user_service_test();
    static void all_tutorials_user_service_test();
};

#endif //OOP_TESTS_H

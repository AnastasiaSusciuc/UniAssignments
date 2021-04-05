//
// Created by susci on 3/20/2021.
//

#include "tests.h"
#include "../DynamicVector/DynamicVector.h"
#include "../Service/AdminService.h"
#include "../Repository/WatchListRepository.h"
#include "../Service/UserService.h"

void Tests::run_all_tests() {
    //std::cout << "Tests started!\n";
    run_domain_tests();
    run_dynamic_array_tests();
    run_repository_tests();
    run_admin_service_tests();
    //std::cout << "Tests ended!\n";
}

// ------ domain Tests -------------------------------------------------------------------------------------------------
void Tests::create_tutorial_test() {

    Tutorial tutorial_test = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};

    assert(tutorial_test.get_title() == "TEST");
    assert(tutorial_test.get_presenter() == "ANI");
    assert(tutorial_test.get_duration() == std::make_pair(21, 10));
    assert(tutorial_test.get_number_of_likes() == 5);
    assert(tutorial_test.get_link() == "https://www.youtube.com/watch?v=BSzSn-PRdtI");

    tutorial_test.set_title("CHANGED TITLE");
    tutorial_test.set_presenter("CHANGED PRESENTER");
    tutorial_test.set_duration(std::make_pair(9, 9));
    tutorial_test.set_likes(10);
    tutorial_test.set_link("https://www.youtube.com/watch?v=fwK7ggA3-bU");

    assert(tutorial_test.get_title() == "CHANGED TITLE");
    assert(tutorial_test.get_presenter() == "CHANGED PRESENTER");
    assert(tutorial_test.get_duration() == std::make_pair(9, 9));
    assert(tutorial_test.get_number_of_likes() == 10);
    assert(tutorial_test.get_link() == "https://www.youtube.com/watch?v=fwK7ggA3-bU");

}

void Tests::run_domain_tests() {
    create_tutorial_test();
    //std::cout << "DOMAIN TESTS FINISHED\n";
}
// ------ dynamic array Tests ------------------------------------------------------------------------------------------

void Tests::create_dynamic_array_test()
{
    DynamicVector<int> array{10};
    assert(array.capacity() == 10);
}

void Tests::resize_dynamic_array_test()
{
    DynamicVector<int> array{10};
    assert(array.capacity() == 10);
    array.resize_dynamic_vector();
    assert(array.capacity() == 20);
}

void Tests::add_element_in_dynamic_array_test()
{
    DynamicVector<int> array{3};
    array.append(2);
    array.append(21);
    array.append(3);
    array.append(31);
    array.append(4);
    assert(array.size() == 5);
    assert(array.capacity() == 6);
}

void Tests::search_element_in_dynamic_array_test()
{
    DynamicVector<int> array{10};
    array.append(2);
    array.append(21);
    array.append(3);
    array.append(31);
    array.append(4);
    assert(array.size() == 5);

    int position_found = array.search_element(21);
    assert(position_found == 1);

    int position_not_found = array.search_element(9);
    assert(position_not_found == -1);
}

void Tests::remove_element_in_dynamic_array_test()
{
    DynamicVector<int> array{10};
    array.append(2);
    array.append(21);
    array.append(3);
    array.append(31);
    array.append(4);
    assert(array.size() == 5);

    array.remove(4);
    assert(array.size() == 4);

    array.remove(9);
    assert(array.size() == 4);

    array.remove(2);
    assert(array.size() == 3);

    assert(array[0] == 21);
    assert(array[1] == 3);
    assert(array[2] == 31);

}

void Tests::update_element_in_dynamic_array_test()
{
    DynamicVector<int> array{10};
    array.append(2);
    array.append(21);
    array.append(3);
    array.append(31);
    array.append(4);

    assert(array.size() == 5);
    assert(array[1] == 21);

    array.update(21, 51);

    assert(array.size() == 5);

    assert(array[0] == 2);
    assert(array[1] == 51);
    assert(array[2] == 3);
    assert(array[3] == 31);
    assert(array[4] == 4);

    try {
        array[10];
    }
    catch (std::exception Exception){
        assert(true);
    }

}

void Tests::run_dynamic_array_tests() {
    create_dynamic_array_test();
    resize_dynamic_array_test();
    add_element_in_dynamic_array_test();
    search_element_in_dynamic_array_test();
    remove_element_in_dynamic_array_test();
    update_element_in_dynamic_array_test();
    //std::cout << "DYNAMIC ARRAY TESTS FINISHED\n";
}

// ------ repository Tests ---------------------------------------------------------------------------------------------

void Tests::run_repository_tests() {
    run_admin_repository_tests();
    run_user_repository_tests();
}

void Tests::run_admin_repository_tests() {
    create_repository_test();
    add_tutorial_in_repository_test();
    remove_tutorial_from_repository_test();
    update_tutorial_from_repository_test();
    all_tutorials_from_repository_test();
    admin_increase_likes_in_repository_test();

}

void Tests::run_user_repository_tests() {
    create_watchlist_repository_test();
    add_tutorial_in_watchlist_test();
    remove_tutorial_from_watchlist_test();
    all_tutorials_from_watchlist_test();
    get_tutorial_by_position_test();
}


void Tests::create_repository_test() {
    Repository repository;
    assert(repository.size_tutorials_list() == 0);
    //std::cout << "REPO CREATE TESTS FINISHED\n";
}

void Tests::add_tutorial_in_repository_test() {
    Repository repository;
    Tutorial tutorial_test = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};

    int success = repository.admin_add_tutorial_in_repository(tutorial_test);
    assert(repository.size_tutorials_list() == 1);
    assert(success == 0);

    int not_success = repository.admin_add_tutorial_in_repository(tutorial_test);
    assert(repository.size_tutorials_list() == 1);
    assert(not_success == 1);
    //std::cout << "REPO ADD TESTS FINISHED\n";
}

void Tests::remove_tutorial_from_repository_test() {
    Repository repository;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};

    int success;
    success = repository.admin_add_tutorial_in_repository(tutorial_test1);
    assert(success == 0);
    success = repository.admin_add_tutorial_in_repository(tutorial_test2);
    assert(success == 0);

    success = repository.admin_remove_tutorial_in_repository("https://www.youtube.com/watch?v=BSzSn-PRdtI");
    assert(success == 0);

    assert(repository.size_tutorials_list() == 1);

    success = repository.admin_remove_tutorial_in_repository("not a link");
    assert(success == 1);
    //::cout << "REPO REMOVE TESTS FINISHED\n";
}

void Tests::update_tutorial_from_repository_test() {
    Repository repository;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};
    int success;
    success = repository.admin_add_tutorial_in_repository(tutorial_test1);
    assert(success == 0);
    success = repository.admin_add_tutorial_in_repository(tutorial_test2);
    assert(success == 0);
    success = repository.admin_update_tutorial_in_repository("https://www.youtube.com/watch?v=BSzSn-PRdtI", "UPDATE TITLE", "UPDATE PRESENTER", std::make_pair(1, 1), 99);
    assert(success == 0);

    Tutorial tutorial0 = repository.get_tutorial_by_position(0);

    assert(tutorial0.get_link() == "https://www.youtube.com/watch?v=BSzSn-PRdtI");
    assert(tutorial0.get_title() == "UPDATE TITLE");
    assert(tutorial0.get_presenter() == "UPDATE PRESENTER");
    assert(tutorial0.get_duration() == std::make_pair(1, 1));
    assert(tutorial0.get_number_of_likes() == 99);

    Tutorial tutorial1 = repository.get_tutorial_by_position(1);

    assert(tutorial1.get_link() == "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(tutorial1.get_title() == "TEST2");
    assert(tutorial1.get_presenter() == "MARA");
    assert(tutorial1.get_duration() == std::make_pair(22, 10));
    assert(tutorial1.get_number_of_likes() == 6);

    success = repository.admin_update_tutorial_in_repository("NOT A LINK", "UPDATE TITLE", "UPDATE PRESENTER", std::make_pair(1, 1), 99);
    assert(success == 1);

    try {
        Tutorial tutorial_failed = repository.get_tutorial_by_position(100);
    }
    catch (std::exception Exception){
        assert(true);
    }
    //std::cout << "REPO UPDATE TESTS FINISHED\n";
}


void Tests::all_tutorials_from_repository_test() {
    Repository repository;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};
    int success;
    success = repository.admin_add_tutorial_in_repository(tutorial_test1);
    assert(success == 0);
    success = repository.admin_add_tutorial_in_repository(tutorial_test2);
    assert(success == 0);

    std::vector <Tutorial> all_tutorials = repository.all_tutorials_from_repository();

    assert(all_tutorials[0].get_title() == "TEST");
    assert(all_tutorials[1].get_title() == "TEST2");

    assert(all_tutorials[0].get_presenter() == "ANI");
    assert(all_tutorials[1].get_presenter() == "MARA");

    assert(all_tutorials[0].get_duration() == std::make_pair(21, 10));
    assert(all_tutorials[1].get_duration() == std::make_pair(22, 10));

    assert(all_tutorials[0].get_number_of_likes() == 5);
    assert(all_tutorials[1].get_number_of_likes() == 6);

    assert(all_tutorials[0].get_link() == "https://www.youtube.com/watch?v=BSzSn-PRdtI");
    assert(all_tutorials[1].get_link() == "https://www.youtube.com/watch?v=8RVKLcaIAE8");

}


void Tests::admin_increase_likes_in_repository_test() {
    Repository repository;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};
    int success;
    success = repository.admin_add_tutorial_in_repository(tutorial_test1);
    assert(success == 0);
    success = repository.admin_add_tutorial_in_repository(tutorial_test2);
    assert(success == 0);
    success = repository.admin_increase_likes_in_repository("https://www.youtube.com/watch?v=BSzSn-PRdtI");
    assert(success == 0);
    std::vector <Tutorial> all_tutorials = repository.all_tutorials_from_repository();

    assert(all_tutorials[0].get_title() == "TEST");
    assert(all_tutorials[1].get_title() == "TEST2");

    assert(all_tutorials[0].get_presenter() == "ANI");
    assert(all_tutorials[1].get_presenter() == "MARA");

    assert(all_tutorials[0].get_duration() == std::make_pair(21, 10));
    assert(all_tutorials[1].get_duration() == std::make_pair(22, 10));

    assert(all_tutorials[0].get_number_of_likes() == 6);
    assert(all_tutorials[1].get_number_of_likes() == 6);

    assert(all_tutorials[0].get_link() == "https://www.youtube.com/watch?v=BSzSn-PRdtI");
    assert(all_tutorials[1].get_link() == "https://www.youtube.com/watch?v=8RVKLcaIAE8");

    success = repository.admin_increase_likes_in_repository("not a valid link!");
    assert(success == 1);

}

void Tests::create_watchlist_repository_test() {
    WatchListRepository repository;
    assert(repository.size_tutorials_list() == 0);
}

void Tests::add_tutorial_in_watchlist_test() {
    WatchListRepository repository;
    assert(repository.size_tutorials_list() == 0);
    Tutorial tutorial_test = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};

    int success = repository.user_add_tutorial_in_repository(tutorial_test);
    assert(repository.size_tutorials_list() == 1);
    assert(success == 0);

    int not_success = repository.user_add_tutorial_in_repository(tutorial_test);
    assert(repository.size_tutorials_list() == 1);
    assert(not_success == 1);
}

void Tests::remove_tutorial_from_watchlist_test() {
    WatchListRepository repository;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};

    int success;
    success = repository.user_add_tutorial_in_repository(tutorial_test1);
    assert(success == 0);
    success = repository.user_add_tutorial_in_repository(tutorial_test2);
    assert(success == 0);

    success = repository.user_remove_tutorial_in_repository("https://www.youtube.com/watch?v=BSzSn-PRdtI");
    assert(success == 0);

    assert(repository.size_tutorials_list() == 1);

    success = repository.user_remove_tutorial_in_repository("not a link");
    assert(success == 1);
}

void Tests::all_tutorials_from_watchlist_test() {
    WatchListRepository repository;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};
    int success;
    success = repository.user_add_tutorial_in_repository(tutorial_test1);
    assert(success == 0);
    success = repository.user_add_tutorial_in_repository(tutorial_test2);
    assert(success == 0);

    std::vector <Tutorial> all_tutorials = repository.all_tutorials_from_repository();

    assert(all_tutorials[0].get_title() == "TEST");
    assert(all_tutorials[1].get_title() == "TEST2");

    assert(all_tutorials[0].get_presenter() == "ANI");
    assert(all_tutorials[1].get_presenter() == "MARA");

    assert(all_tutorials[0].get_duration() == std::make_pair(21, 10));
    assert(all_tutorials[1].get_duration() == std::make_pair(22, 10));

    assert(all_tutorials[0].get_number_of_likes() == 5);
    assert(all_tutorials[1].get_number_of_likes() == 6);

    assert(all_tutorials[0].get_link() == "https://www.youtube.com/watch?v=BSzSn-PRdtI");
    assert(all_tutorials[1].get_link() == "https://www.youtube.com/watch?v=8RVKLcaIAE8");

}

void Tests::get_tutorial_by_position_test() {
    WatchListRepository repository;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};
    int success;
    success = repository.user_add_tutorial_in_repository(tutorial_test1);
    assert(success == 0);
    success = repository.user_add_tutorial_in_repository(tutorial_test2);
    assert(success == 0);

    Tutorial tutorial_found = repository.get_tutorial_by_position(0);

    assert(tutorial_found.get_title() == "TEST");

    assert(tutorial_found.get_presenter() == "ANI");

    assert(tutorial_found.get_duration() == std::make_pair(21, 10));

    assert(tutorial_found.get_number_of_likes() == 5);

    assert(tutorial_found.get_link() == "https://www.youtube.com/watch?v=BSzSn-PRdtI");

    try {
        Tutorial tutorial_failed = repository.get_tutorial_by_position(100);
    }
    catch (std::exception Exception){
        assert(true);
    }

}
// ------ Admin Service Tests ------------------------------------------------------------------------------------------
void Tests::run_admin_service_tests() {

    run_admin_service_test();
    run_user_service_test();
}

void Tests::run_admin_service_test() {
    add_tutorial_admin_service_test();
    remove_tutorial_admin_service_test();
    update_tutorial_admin_service_test();
    all_tutorials_service_test();
    tutorials_by_presenter_service_test();
    increase_likes_service_test();
}

void Tests::run_user_service_test() {
    add_tutorial_user_service_test();
    remove_tutorial_user_service_test();
    all_tutorials_user_service_test();
}

void Tests::add_tutorial_admin_service_test() {
    Repository repository;
    AdminService admin_service = {repository};
    int success = admin_service.add_tutorial_admin_service("Hold on","Rusko", std::make_pair(3, 58), 41876, "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(success == 0);

    success = admin_service.add_tutorial_admin_service("NOT Hold on","Rusko", std::make_pair(3, 58), 41876, "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(success == 1);

    //std::cout << "SERVICE ADD TESTS FINISHED\n";
}

void Tests::remove_tutorial_admin_service_test() {
    Repository repository;
    AdminService admin_service = {repository};
    int success;

    admin_service.add_tutorial_admin_service("Hold on","Rusko", std::make_pair(3, 58), 41876, "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    admin_service.add_tutorial_admin_service("Waiting all night","Rudimental", std::make_pair(5, 15), 980762, "https://www.youtube.com/watch?v=M97vR2V4vTs");

    success = admin_service.remove_tutorial_admin_service("https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(success == 0);

    success = admin_service.remove_tutorial_admin_service("https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(success == 1);

    Tutorial tutorial1 = admin_service.get_tutorial_by_position_admin_service(0);

    assert(tutorial1.get_title() == "Waiting all night");
    assert(tutorial1.get_presenter() == "Rudimental");
    assert(tutorial1.get_duration() == std::make_pair(5, 15));
    assert(tutorial1.get_number_of_likes() == 980762);
    assert(tutorial1.get_link() == "https://www.youtube.com/watch?v=M97vR2V4vTs");
    //std::cout << "SERVICE REMOVE TESTS FINISHED\n";
}

void Tests::update_tutorial_admin_service_test() {
    Repository repository;
    AdminService admin_service = {repository};
    int success;

    admin_service.add_tutorial_admin_service("Waiting all night","Rudimental", std::make_pair(5, 15), 980762, "https://www.youtube.com/watch?v=M97vR2V4vTs");
    success = admin_service.update_tutorial_admin_service("https://www.youtube.com/watch?v=M97vR2V4vTs", "Updated title", "Updated presenter", std::make_pair(22, 22), 8);
    assert(success == 0);

    Tutorial tutorial1 = admin_service.get_tutorial_by_position_admin_service(0);

    assert(tutorial1.get_title() == "Updated title");
    assert(tutorial1.get_presenter() == "Updated presenter");
    assert(tutorial1.get_duration() == std::make_pair(22, 22));
    assert(tutorial1.get_number_of_likes() == 8);
    assert(tutorial1.get_link() == "https://www.youtube.com/watch?v=M97vR2V4vTs");
    //std::cout << "SERVICE UPDATE TESTS FINISHED\n";
}

void Tests::all_tutorials_service_test() {
    Repository repository;
    AdminService admin_service = {repository};

    admin_service.add_tutorial_admin_service("Hold on","Rusko", std::make_pair(3, 58), 41876, "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    admin_service.add_tutorial_admin_service("Waiting all night","Rudimental", std::make_pair(5, 15), 980762, "https://www.youtube.com/watch?v=M97vR2V4vTs");

    std::vector<Tutorial> all_tutorials = admin_service.all_tutorials_service();

    assert(admin_service.size_repo() == 2);

    assert(all_tutorials[0].get_title() == "Hold on");
    assert(all_tutorials[1].get_title() == "Waiting all night");

    assert(all_tutorials[0].get_presenter() == "Rusko");
    assert(all_tutorials[1].get_presenter() == "Rudimental");

    assert(all_tutorials[0].get_duration() == std::make_pair(3, 58));
    assert(all_tutorials[1].get_duration() == std::make_pair(5, 15));

    assert(all_tutorials[0].get_number_of_likes() == 41876);
    assert(all_tutorials[1].get_number_of_likes() == 980762);

    assert(all_tutorials[0].get_link() == "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(all_tutorials[1].get_link() == "https://www.youtube.com/watch?v=M97vR2V4vTs");
}

void Tests::tutorials_by_presenter_service_test() {
    Repository repository;
    AdminService admin_service = {repository};

    admin_service.add_tutorial_admin_service("Hold on","Rusko", std::make_pair(3, 58), 41876, "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    admin_service.add_tutorial_admin_service("Waiting all night","Rudimental", std::make_pair(5, 15), 980762, "https://www.youtube.com/watch?v=M97vR2V4vTs");

    std::vector<Tutorial> tutorials_filtered = admin_service.tutorials_by_presenter_service("sk");

    assert(tutorials_filtered.size() == 1);

    assert(tutorials_filtered[0].get_title() == "Hold on");
    assert(tutorials_filtered[0].get_presenter() == "Rusko");
    assert(tutorials_filtered[0].get_duration() == std::make_pair(3, 58));
    assert(tutorials_filtered[0].get_number_of_likes() == 41876);
    assert(tutorials_filtered[0].get_link() == "https://www.youtube.com/watch?v=8RVKLcaIAE8");


    std::vector<Tutorial> all_tutorials = admin_service.tutorials_by_presenter_service("");

    assert(admin_service.size_repo() == 2);

    assert(all_tutorials[0].get_title() == "Hold on");
    assert(all_tutorials[1].get_title() == "Waiting all night");

    assert(all_tutorials[0].get_presenter() == "Rusko");
    assert(all_tutorials[1].get_presenter() == "Rudimental");

    assert(all_tutorials[0].get_duration() == std::make_pair(3, 58));
    assert(all_tutorials[1].get_duration() == std::make_pair(5, 15));

    assert(all_tutorials[0].get_number_of_likes() == 41876);
    assert(all_tutorials[1].get_number_of_likes() == 980762);

    assert(all_tutorials[0].get_link() == "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(all_tutorials[1].get_link() == "https://www.youtube.com/watch?v=M97vR2V4vTs");
}

void Tests::increase_likes_service_test() {
    Repository repository;
    AdminService admin_service = {repository};

    admin_service.add_tutorial_admin_service("Hold on","Rusko", std::make_pair(3, 58), 41876, "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    admin_service.add_tutorial_admin_service("Waiting all night","Rudimental", std::make_pair(5, 15), 980762, "https://www.youtube.com/watch?v=M97vR2V4vTs");

    admin_service.increase_likes_tutorial_service("https://www.youtube.com/watch?v=8RVKLcaIAE8");

    std::vector<Tutorial> all_tutorials = admin_service.all_tutorials_service();

    assert(admin_service.size_repo() == 2);

    assert(all_tutorials[0].get_title() == "Hold on");
    assert(all_tutorials[1].get_title() == "Waiting all night");

    assert(all_tutorials[0].get_presenter() == "Rusko");
    assert(all_tutorials[1].get_presenter() == "Rudimental");

    assert(all_tutorials[0].get_duration() == std::make_pair(3, 58));
    assert(all_tutorials[1].get_duration() == std::make_pair(5, 15));

    assert(all_tutorials[0].get_number_of_likes() == 41877);
    assert(all_tutorials[1].get_number_of_likes() == 980762);

    assert(all_tutorials[0].get_link() == "https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(all_tutorials[1].get_link() == "https://www.youtube.com/watch?v=M97vR2V4vTs");
}

void Tests::add_tutorial_user_service_test() {
    WatchListRepository repository;
    UserService user_service = {repository};
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};

    int success = user_service.add_tutorial_watch_list_user_service(tutorial_test1);
    assert(success == 0);

    success = user_service.add_tutorial_watch_list_user_service(tutorial_test1);
    assert(success == 1);
}

void Tests::remove_tutorial_user_service_test() {
    WatchListRepository repository;
    UserService user_service = {repository};
    int success;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};

    success = user_service.add_tutorial_watch_list_user_service(tutorial_test1);
    assert(success == 0);

    success = user_service.add_tutorial_watch_list_user_service(tutorial_test2);
    assert(success == 0);

    success = user_service.remove_tutorial_watch_list_user_service("https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(success == 0);

    success = user_service.remove_tutorial_watch_list_user_service("https://www.youtube.com/watch?v=8RVKLcaIAE8");
    assert(success == 1);

    Tutorial tutorial1 = user_service.get_tutorial_by_position_watch_list_user_service(0);

    assert(tutorial1.get_title() == "TEST");
    assert(tutorial1.get_presenter() == "ANI");
    assert(tutorial1.get_duration() == std::make_pair(21, 10));
    assert(tutorial1.get_number_of_likes() == 5);
    assert(tutorial1.get_link() == "https://www.youtube.com/watch?v=BSzSn-PRdtI");
}

void Tests::all_tutorials_user_service_test() {
    WatchListRepository repository;
    UserService user_service = {repository};
    int success;
    Tutorial tutorial_test1 = {"TEST", "ANI", std::make_pair(21, 10), 5, "https://www.youtube.com/watch?v=BSzSn-PRdtI"};
    Tutorial tutorial_test2 = {"TEST2", "MARA", std::make_pair(22, 10), 6, "https://www.youtube.com/watch?v=8RVKLcaIAE8"};

    success = user_service.add_tutorial_watch_list_user_service(tutorial_test1);
    assert(success == 0);

    success = user_service.add_tutorial_watch_list_user_service(tutorial_test2);
    assert(success == 0);

    std::vector <Tutorial> all_tutorial = user_service.all_tutorials_watch_list_service();

    assert(user_service.size_watch_list_repo() == 2);

    assert(all_tutorial[0].get_title() == "TEST");
    assert(all_tutorial[1].get_title() == "TEST2");

    assert(all_tutorial[0].get_presenter() == "ANI");
    assert(all_tutorial[1].get_presenter() == "MARA");

}

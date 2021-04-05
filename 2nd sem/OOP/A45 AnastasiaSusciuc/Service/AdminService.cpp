//
// Created by susci on 3/21/2021.
//

#include <cstring>
#include "AdminService.h"
#include <iostream>

AdminService::AdminService(Repository &repository) : repository{repository} {
}

AdminService::~AdminService() = default;


int AdminService::add_tutorial_admin_service(const std::string &title,
                                       const std::string &presenter,
                                       const std::pair<int, int> &duration,
                                       int number_of_likes,
                                       const std::string &link) {
    Tutorial tutorial = {title, presenter, duration, number_of_likes, link};
    return repository.admin_add_tutorial_in_repository(tutorial);
}

int AdminService::remove_tutorial_admin_service(const std::string &link) {
    return repository.admin_remove_tutorial_in_repository(link);
}

Tutorial AdminService::get_tutorial_by_position_admin_service(int position) {
    return repository.get_tutorial_by_position(position);
}

int AdminService::update_tutorial_admin_service(const std::string &tutorial_to_update_link,
                                                const std::string &new_tutorial_title,
                                                const std::string &new_tutorial_presenter,
                                                const std::pair<int, int> &new_duration, int new_number_of_likes) {
    return repository.admin_update_tutorial_in_repository(tutorial_to_update_link,
                                                          new_tutorial_title,
                                                          new_tutorial_presenter,
                                                          new_duration,
                                                          new_number_of_likes);
}

std::vector<Tutorial> AdminService::all_tutorials_service() {
    return repository.all_tutorials_from_repository();
}

int AdminService::size_repo() const {
    return repository.size_tutorials_list();
}

std::vector<Tutorial> AdminService::tutorials_by_presenter_service(const std::string &substring_presenter) {
    std::vector <Tutorial> all_tutorial = repository.all_tutorials_from_repository();
    std::vector <Tutorial> presenter_tutorial;


    for (auto & it : all_tutorial)
    {
        if (it.get_presenter().find(substring_presenter) != std::string::npos)
            presenter_tutorial.push_back(it);
    }
    return presenter_tutorial;
}

int AdminService::increase_likes_tutorial_service(const std::string &link) {
    return repository.admin_increase_likes_in_repository(link);
}

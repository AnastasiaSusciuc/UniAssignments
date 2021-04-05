//
// Created by susci on 3/31/2021.
//

#include "UserService.h"

UserService::UserService(WatchListRepository &repository): repository{repository} {

}

UserService::~UserService() = default;

int UserService::add_tutorial_watch_list_user_service(const Tutorial& tutorial) {

    return repository.user_add_tutorial_in_repository(tutorial);
}

int UserService::remove_tutorial_watch_list_user_service(const std::string &link) {
    return repository.user_remove_tutorial_in_repository(link);
}


std::vector<Tutorial> UserService::all_tutorials_watch_list_service() {
    return repository.all_tutorials_from_repository();
}

int UserService::size_watch_list_repo() const {
    return repository.size_tutorials_list();
}

Tutorial UserService::get_tutorial_by_position_watch_list_user_service(int position) {
    return repository.get_tutorial_by_position(position);
}

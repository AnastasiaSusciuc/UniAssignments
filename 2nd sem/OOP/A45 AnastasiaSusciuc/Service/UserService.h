//
// Created by susci on 3/31/2021.
//

#ifndef UNTITLED_USERSERVICE_H
#define UNTITLED_USERSERVICE_H

#include "../Repository/WatchListRepository.h"

class UserService{

private:
    WatchListRepository& repository;

public:
    UserService(WatchListRepository& repository);
    ~UserService();
    int add_tutorial_watch_list_user_service(const Tutorial& tutorial);
    int remove_tutorial_watch_list_user_service(const std::string &link);
    Tutorial get_tutorial_by_position_watch_list_user_service(int position);
    std::vector<Tutorial> all_tutorials_watch_list_service();
    int size_watch_list_repo() const;
};
#endif //UNTITLED_USERSERVICE_H

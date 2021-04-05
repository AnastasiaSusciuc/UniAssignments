//
// Created by susci on 3/31/2021.
//

#include "WatchListRepository.h"

WatchListRepository::WatchListRepository() = default;

WatchListRepository::~WatchListRepository() = default;

int WatchListRepository::user_add_tutorial_in_repository(const Tutorial &tutorial) {
    for (int i = 0; i < tutorials_list.size(); i++)
    {
        Tutorial tutorial_i = tutorials_list[i];
        if (tutorial_i.get_link() == tutorial.get_link())
            return 1;
    }
    tutorials_list.append(tutorial);
    return 0;
}

int WatchListRepository::user_remove_tutorial_in_repository(const std::string &tutorial_link) {
    for (int i = 0; i < tutorials_list.size(); i++)
    {
        Tutorial tutorial_i = tutorials_list[i];
        if (tutorial_i.get_link() == tutorial_link)
        {
            tutorials_list.remove(tutorial_i);
            return 0;
        }
    }
    return 1;
}

int WatchListRepository::size_tutorials_list() const {
    return tutorials_list.size();
}

Tutorial WatchListRepository::get_tutorial_by_position(int position) {
    if (position < 0 || position >= tutorials_list.size())
        throw std::runtime_error("Invalid position");
    return tutorials_list[position];
}

std::vector<Tutorial> WatchListRepository::all_tutorials_from_repository() {
    std::vector <Tutorial> all_tutorials;

    all_tutorials.reserve(tutorials_list.size());
    for (int i = 0; i < tutorials_list.size(); i++) {
        all_tutorials.push_back(tutorials_list[i]);
    }

    return all_tutorials;
}

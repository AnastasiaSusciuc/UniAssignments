//
// Created by susci on 3/21/2021.
//

#include <stdexcept>
#include "TutorialsRepository.h"


Repository::Repository() = default;

Repository::~Repository()= default;

int Repository::size_tutorials_list() const{
    return tutorials_list.size();
}


int Repository::admin_add_tutorial_in_repository(const Tutorial& tutorial){

    for (int i = 0; i < tutorials_list.size(); i++)
    {
        Tutorial tutorial_i = tutorials_list[i];
        if (tutorial_i.get_link() == tutorial.get_link())
            return 1;
    }
    tutorials_list.append(tutorial);
    return 0;
}

int Repository::admin_remove_tutorial_in_repository(const std::string &tutorial_link) {
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

int Repository::admin_update_tutorial_in_repository(const std::string &tutorial_to_update_link,
                                                    const std::string &new_tutorial_title,
                                                    const std::string &new_tutorial_presenter,
                                                    const std::pair<int, int> &new_duration, int new_number_of_likes)
                                                    {
    for (int i = 0; i < tutorials_list.size(); i++)
    {
        if (tutorials_list[i].get_link() == tutorial_to_update_link)
        {
            tutorials_list[i].set_title(new_tutorial_title);
            tutorials_list[i].set_presenter(new_tutorial_presenter);
            tutorials_list[i].set_duration(new_duration);
            tutorials_list[i].set_likes(new_number_of_likes);
            return 0;
        }
    }
    return 1;

}

Tutorial Repository::get_tutorial_by_position(int position) {
    if (position < 0 || position >= tutorials_list.size())
        throw std::runtime_error("Invalid position");
    return tutorials_list[position];
}

std::vector<Tutorial> Repository::all_tutorials_from_repository() {
    std::vector <Tutorial> all_tutorials;

    all_tutorials.reserve(tutorials_list.size());
    for (int i = 0; i < tutorials_list.size(); i++) {
        all_tutorials.push_back(tutorials_list[i]);
    }

    return all_tutorials;
}


int Repository::admin_increase_likes_in_repository(const std::string &tutorial_link) {
    for (int i = 0; i < tutorials_list.size(); i++)
    {
        Tutorial tutorial_i = tutorials_list[i];
        if (tutorial_i.get_link() == tutorial_link)
        {
            tutorials_list[i].set_likes(tutorials_list[i].get_number_of_likes()+1);
            return 0;
        }
    }
    return 1;
}

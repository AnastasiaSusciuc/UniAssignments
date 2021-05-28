//
// Created by susci on 3/31/2021.
//

#include "WatchListRepository.h"

WatchListRepository::WatchListRepository(const std::string& file_name, const std::string& read_file) {
    tutorial_file_name = file_name;
    read_file_name = read_file;
    load_tutorials_from_file();
};

WatchListRepository::~WatchListRepository() = default;

void WatchListRepository::load_tutorials_from_file() {
//    if (read_file_name.empty())
//        return;

//    Tutorial tutorial_from_file;
//    std::ifstream fin(read_file_name);
//
//    while (fin >> tutorial_from_file) {
//
//        if(std::find(watch_list.begin(), watch_list.end(), tutorial_from_file) == watch_list.end())
//            watch_list.push_back(tutorial_from_file);
//    }
//    fin.close();
}

//void WatchListRepository::write_tutorials_to_file() {
//    if (tutorial_file_name.empty())
//        return;
//    std::ofstream fout(tutorial_file_name);
//    for (const Tutorial& movieToWrite : watch_list) {
//        fout << movieToWrite << '\n';
//    }
//    fout.close();
//}

void WatchListRepository::user_add_tutorial_in_repository(const Tutorial &tutorial) {
    for (auto & it : watch_list)
    {
        if (it.get_link() == tutorial.get_link())
            throw RepositoryException("There is already a tutorial with this link in the repository!\n");
    }
    watch_list.push_back(tutorial);
    write_tutorials_to_file();
}

void WatchListRepository::user_remove_tutorial_in_repository(const std::string &tutorial_link) {
    for (auto it = watch_list.begin(); it != watch_list.end(); it++)
    {
        if (it->get_link() == tutorial_link)
        {
            watch_list.erase(it);
            write_tutorials_to_file();
            return;
        }
    }
    throw RepositoryException("There is no such a tutorial to be erased!\n");
}

int WatchListRepository::size_tutorials_list() const {
    return watch_list.size();
}

Tutorial WatchListRepository::get_tutorial_by_position(int position) {
    if (position < 0 || position >= watch_list.size())
        throw std::runtime_error("Invalid position");
    return watch_list[position];
}

std::vector<Tutorial> WatchListRepository::all_tutorials_from_repository() {
    std::vector <Tutorial> all_tutorials;

    all_tutorials.reserve(watch_list.size());
    for (auto & i : watch_list) {
        all_tutorials.push_back(i);
    }

    return all_tutorials;
}

std::string WatchListRepository::get_file_name() {
    return this->tutorial_file_name;
}

//
// Created by susci on 3/21/2021.
//

#include "FileRepository.h"
#include <stdexcept>


FileRepository::FileRepository(const std::string& file_name){
    tutorial_file_name = file_name;
    load_tutorials_from_file();
};

FileRepository::~FileRepository()= default;

void FileRepository::load_tutorials_from_file()
{
    Tutorial tutorial_from_file;
    std::ifstream fin(tutorial_file_name);

    while (fin >> tutorial_from_file) {
        if(std::find(tutorials_list.begin(), tutorials_list.end(), tutorial_from_file) == tutorials_list.end())
            tutorials_list.push_back(tutorial_from_file);
    }

    fin.close();
}

void FileRepository::write_tutorials_to_file() {

    std::ofstream fout(tutorial_file_name);
    for (const Tutorial& movieToWrite : tutorials_list) {
        fout << movieToWrite << '\n';
    }
    fout.close();
}

int FileRepository::size_tutorials_list() const{
    return tutorials_list.size();
}

void FileRepository::admin_add_tutorial_in_repository(const Tutorial& tutorial){

    for (auto & it : tutorials_list)
    {
        std::cout << it.get_presenter() << '\n';
        if (it.get_link() == tutorial.get_link())
            throw RepositoryException("There is already a tutorial with this link in the repository!\n");
    }
    tutorials_list.push_back(tutorial);
    write_tutorials_to_file();
}

void FileRepository::admin_remove_tutorial_in_repository(const std::string &tutorial_link) {
    for (auto it = tutorials_list.begin(); it != tutorials_list.end(); it++)
    {
        if (it->get_link() == tutorial_link)
        {
            tutorials_list.erase(it);
            write_tutorials_to_file();
            return;
        }
    }
    throw RepositoryException("There is no such a tutorial to be erased!\n");
}

void FileRepository::admin_update_tutorial_in_repository(const std::string &tutorial_to_update_link,
                                                         const std::string &new_tutorial_title,
                                                         const std::string &new_tutorial_presenter,
                                                         const std::pair<int, int> &new_duration, int new_number_of_likes)
                                                    {
    for (auto & it : tutorials_list)
    {
        if (it.get_link() == tutorial_to_update_link)
        {
            it.set_title(new_tutorial_title);
            it.set_presenter(new_tutorial_presenter);
            it.set_duration(new_duration);
            it.set_likes(new_number_of_likes);
            write_tutorials_to_file();
            return;
        }
    }
    throw RepositoryException("There is no such a tutorial to be updated!\n");
}

Tutorial FileRepository::get_tutorial_by_position(int position) {
    if (position < 0 || position >= tutorials_list.size())
        throw std::runtime_error("Invalid position");
    return tutorials_list[position];
}

std::vector<Tutorial> FileRepository::all_tutorials_from_repository() {
    std::vector <Tutorial> all_tutorials;

    for (auto & i : tutorials_list) {

         all_tutorials.push_back(i);
    }

    return all_tutorials;
}


void FileRepository::admin_increase_likes_in_repository(const std::string &tutorial_link) {
    for (auto & i : tutorials_list)
    {
        Tutorial tutorial_i = i;
        if (tutorial_i.get_link() == tutorial_link)
        {
            i.set_likes(i.get_number_of_likes()+1);
            write_tutorials_to_file();
            return;
        }
    }
    throw RepositoryException("There is no such a tutorial to have its number of likes increased!\n");
}

void FileRepository::erase_file_content() {
    std::ofstream ofs;
    ofs.open("../Files/test.in", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

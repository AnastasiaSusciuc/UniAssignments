//
// Created by susci on 3/21/2021.
//
//
#ifndef OOP_TUTORIALSREPOSITORY_H
#define OOP_TUTORIALSREPOSITORY_H
#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "../Domain/tutorial.h"
#include "../DynamicVector/DynamicVector.h"
#include "../Exception/repository_exception.h"

class FileRepository{
protected:
    std::vector <Tutorial> tutorials_list;
    std::string tutorial_file_name;

public:
    explicit FileRepository(const std::string& fileName);
    ~FileRepository();
    void load_tutorials_from_file();
    void write_tutorials_to_file();
    static void erase_file_content();

    void admin_add_tutorial_in_repository(const Tutorial& tutorial);
    /*
     * description:  adds a new tutorial in the repository of tutorials 'tutorials_list'
     *               it is checked if the new tutorial to be added has a unique link, if so then it is added
     *
     * param1:       tutorial -Tutorial- the tutorial to be added in the repository
     *
     * returns:      -
     *
     * throws:       RepositoryException if there is a tutorial with this link in the repository already
     * */
    void admin_remove_tutorial_in_repository(const std::string &tutorial_link);
    /*
     * description:  removes the tutorial with the link 'tutorial_link' from the repository 'tutorials_list'
     *               if there is no tutorial having 'tutorial_link' as a link, no changes are made
     *
     * param1:       tutorial_link -string- a string that represents the link of the tutorial to be erased
     *
     * returns:      -
     *
     * throws:       RepositoryException if there is no tutorial with this link to be erased from the repository
     * */
    void admin_update_tutorial_in_repository(const std::string &tutorial_to_update_link,
                                            const std::string& new_tutorial_title,
                                            const std::string& new_tutorial_presenter,
                                            const std::pair<int, int>& new_duration,
                                            int new_number_of_likes);
    /*
     * description:  updates the tutorial with the link 'tutorial_to_update_link' from the repository 'tutorials_list'
     *               its title is replaced with 'new_tutorial_title', its presenter with 'new_tutorial_presenter',
     *               its duration with 'new_duration', its number of likes with 'new_number_of_likes'
     *
     * param1:       tutorial_to_update_link -string- the link of the tutorial we want to update; it is unique for every tutorial
     * param2:       new_tutorial_title -string- the title to update the tutorial with
     * param3:       new_tutorial_presenter -string- the presenter to update the tutorial with
     * param4:       new_duration -pair<int, int>- the new duration to update the tutorial with
     * param5:       new_number_of_likes -int- the new number of likes to update the tutorial with
     *
     * returns:      -
     *
     * throws:       RepositoryException if there is no tutorial with this link to be updated in the repository
     * */
    void admin_increase_likes_in_repository(const std::string &tutorial_link);
    /*
     * description:  increases the number of likes of the tutorial having the link 'tutorial_link'
     *
     * param1:       tutorial_link -std::string- the link of the tutorial to increase the number of likes to
     *
     * returns:      -
     *
     * throws:       RepositoryException if there is no tutorial with this link to have its number of likes increased
     * */
    int size_tutorials_list() const;
    /*
     * description: -
     *
     * returns:     the number of tutorials in the repository
     * */
    Tutorial get_tutorial_by_position(int position);
    /*
     * description:  getter for a tutorial from a certain position
     *
     * param1:       position -int- the position we want to get the tutorial from
     *
     * returns:      the tutorial from the position 'position'
     * throws:       runtime_error - the position is not from the range(0..number of tutorials in the repo)
     *
     * */
    std::vector<Tutorial> all_tutorials_from_repository();
    /*
     * description:  gets all the tutorial from the repo
     *
     * returns:      a std::vector <Tutorial> that contains all the tutorials
     * */

};

#endif //OOP_TUTORIALSREPOSITORY_H
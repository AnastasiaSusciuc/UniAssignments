//
// Created by susci on 3/31/2021.
//

#ifndef UNTITLED_WATCHLISTREPOSITORY_H
#define UNTITLED_WATCHLISTREPOSITORY_H

#include "FileRepository.h"

class WatchListRepository{
protected:
    std::vector<Tutorial> watch_list;
    std::string tutorial_file_name;
    std::string read_file_name;

public:

    WatchListRepository(const std::string& file_name = "", const std::string& read_file = "");
    ~WatchListRepository();

    void load_tutorials_from_file();
    virtual void write_tutorials_to_file() = 0;
    virtual std::string get_repo_type() = 0;
    std::string get_file_name() ;

    void user_add_tutorial_in_repository(const Tutorial& tutorial);
    /*
    * description:  adds a new tutorial in the repository of tutorials 'watchlist'
    *               it is checked if the new tutorial to be added has a unique link, if so then it is added
    *
    * param1:       tutorial -Tutorial- the tutorial to be added in the repository
    *
    * returns:      -
    * throws:       RepositoryException if there already a tutorial with this link in the repository
    * */
    void user_remove_tutorial_in_repository(const std::string &tutorial_link);
    /*
     * description:  removes the tutorial with the link 'tutorial_link' from the repository 'watchlist'
     *               if there is no tutorial having 'tutorial_link' as a link, no changes are made
     *
     * param1:       tutorial_link -string- a string that represents the link of the tutorial to be erased
     *
     * returns:      -
     *
     * throws:       RepositoryException if there is not tutorial in the watch_list with this link
     *
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
#endif //UNTITLED_WATCHLISTREPOSITORY_H

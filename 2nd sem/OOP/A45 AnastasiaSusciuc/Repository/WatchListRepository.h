//
// Created by susci on 3/31/2021.
//

#ifndef UNTITLED_WATCHLISTREPOSITORY_H
#define UNTITLED_WATCHLISTREPOSITORY_H

#include "TutorialsRepository.h"

class WatchListRepository{
private:
    DynamicVector<Tutorial> tutorials_list;

public:
    WatchListRepository();
    ~WatchListRepository();
    int user_add_tutorial_in_repository(const Tutorial& tutorial);
    /*
    * description:  adds a new tutorial in the repository of tutorials 'watchlist'
    *               it is checked if the new tutorial to be added has a unique link, if so then it is added
    *
    * param1:       tutorial -Tutorial- the tutorial to be added in the repository
    *
    * returns:      0 - the tutorial was added successfully
    *               1 - the tutorial doesn't have a unique link, therefore it was not added in the repository
    * */
    int user_remove_tutorial_in_repository(const std::string &tutorial_link);
    /*
     * description:  removes the tutorial with the link 'tutorial_link' from the repository 'watchlist'
     *               if there is no tutorial having 'tutorial_link' as a link, no changes are made
     *
     * param1:       tutorial_link -string- a string that represents the link of the tutorial to be erased
     *
     * returns:      0 - the tutorial was successfully erased from 'tutorial_list'
     *               1 - there is no tutorial with this link, no changes were made
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

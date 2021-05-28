//
// Created by susci on 5/10/2021.
//

#ifndef UNTITLED_HTMLWATCHLIST_H
#define UNTITLED_HTMLWATCHLIST_H
#include "WatchListRepository.h"

class HTMLWatchList : public WatchListRepository{

public:
    explicit HTMLWatchList(const std::string& fileName="", const std::string& readFile="");
    void write_tutorials_to_file() override;
    std::string get_repo_type() override;
};


#endif //UNTITLED_HTMLWATCHLIST_H

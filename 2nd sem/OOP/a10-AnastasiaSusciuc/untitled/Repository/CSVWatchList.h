//
// Created by susci on 5/10/2021.
//

#ifndef UNTITLED_CSVWATCHLIST_H
#define UNTITLED_CSVWATCHLIST_H

#include "WatchListRepository.h"


class CSVWatchList : public WatchListRepository{

public:
    CSVWatchList(const std::string& fileName="", const std::string& readFile="");
    void write_tutorials_to_file() override;
    std::string get_repo_type() override;
};



#endif //UNTITLED_CSVWATCHLIST_H

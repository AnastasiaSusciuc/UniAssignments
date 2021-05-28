//
// Created by susci on 5/10/2021.
//

#include "CSVWatchList.h"

CSVWatchList::CSVWatchList(const std::string& fileName, const std::string& read_file) : WatchListRepository(fileName, read_file){
}

void CSVWatchList::write_tutorials_to_file() {
    std::ofstream file_output(tutorial_file_name);
    file_output << "Title, Presenter, Duration, Number of likes, Link\n";
//    if(watch_list.empty())
//        return;
    for (const Tutorial& movieUsed: watch_list) {
        file_output << '"' << movieUsed.get_title() << "\","
                    << '"' << movieUsed.get_presenter() << "\","
                    << '"' << movieUsed.get_duration().first << "\","
                    << '"' << movieUsed.get_duration().second << "\","
                    << '"' << movieUsed.get_number_of_likes() << "\","
                    << '"' << movieUsed.get_link() << '"' << '\n';
    }
    file_output.close();
}

std::string CSVWatchList::get_repo_type() {
    std::string name = "CSV";
    return name;
}


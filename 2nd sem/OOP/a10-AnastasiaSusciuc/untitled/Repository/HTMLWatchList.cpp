//
// Created by susci on 5/10/2021.
//

#include "HTMLWatchList.h"

HTMLWatchList::HTMLWatchList(const std::string &fileName, const std::string& readFile) : WatchListRepository(fileName, readFile) {

}

void HTMLWatchList::write_tutorials_to_file() {
    std::ofstream file_output(tutorial_file_name);
    file_output << "<!DOCTYPE html>\n<html><head><title>Watchlist</title></head><body>\n";
    file_output << "<table border=\"1\">\n";
    file_output
            << "<tr><td>Title</td><td>Presenter</td><td>Duration</td><td>Number of likes</td><td>Link</td></tr>\n";
    for (const Tutorial &movieUsed: watch_list) {
        file_output << "<tr><td>" << movieUsed.get_title() << "</td>"
                   << "<td>" << movieUsed.get_presenter() << "</td>"
                   << "<td>" << movieUsed.get_duration().first << "</td>"
                   << "<td>" << movieUsed.get_duration().second << "</td>"
                   << "<td>" << movieUsed.get_number_of_likes() << "</td>"
                   << "<td><a href=\"" << movieUsed.get_link() << "\">" << movieUsed.get_link() << "</a></td>" << '\n';
    }
    file_output << "</table></body></html>";
    file_output.close();
}

std::string HTMLWatchList::get_repo_type() {
    std::string name = "HTML";
    return name;
}
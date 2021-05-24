//
// Created by susci on 5/24/2021.
//

#ifndef UNTITLED1_REPO_H
#define UNTITLED1_REPO_H
#include "TimeInterval.h"
#include <fstream>

class Repo {
private:
    std::vector<TimeInterval> time_intervals;
public:
    Repo() = default;

    void read_from_file_repo();

    void add_product(const TimeInterval&);

    void delete_from_repo(int pos);

    std::vector<TimeInterval> get_all() const;

    int get_pos(const std::string& _name);

    void write_to_file();

    TimeInterval get_product_by_pos_repo(int pos);
};


#endif //UNTITLED1_REPO_H

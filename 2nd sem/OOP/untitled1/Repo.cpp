//
// Created by susci on 5/24/2021.
//

#include "Repo.h"
#include <iostream>

void Repo::read_from_file_repo() {
    std::ifstream file;
    TimeInterval p;
    file.open("C:/Users/susci/Desktop/UniAssignments/2nd sem/OOP/untitled1/weather.txt");
    while (file >> p){
//        std::cout << p.toString() << " ";
        this->add_product(p);
    }
}

void Repo::add_product(const TimeInterval &p) {
    this->time_intervals.push_back(p);
}

void Repo::delete_from_repo(int pos) {
    this->time_intervals.erase(this->time_intervals.begin() + pos);
}

std::vector<TimeInterval> Repo::get_all() const {
    return this->time_intervals;
}

int Repo::get_pos(const std::string &_name) {
//    std::vector<TimeInterval> all_products = this->get_all();
//    int i = 0;
//    for (auto p : all_products){
//        if (p.getDescription() == _name)
//            return i;
//        i++;
//    }
//    return -1;
}

void Repo::write_to_file() {
    std::ofstream file;
    file.open ("weather.txt");
    std::vector<TimeInterval> all_products = this->get_all();
    for (auto d : all_products){
        file << d << std::endl;
    }
    file.close();
}

TimeInterval Repo::get_product_by_pos_repo(int pos) {
//    return TimeInterval(0, 0, 0, __cxx11::basic_string());
}

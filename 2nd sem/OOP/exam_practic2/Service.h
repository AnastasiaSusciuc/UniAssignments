//
// Created by octat on 6/18/2021.
//

#ifndef SECONDARY_SERVICE_H
#define SECONDARY_SERVICE_H

#pragma once
#include "Repo.h"

class Service
{
private:
    Repo &repo;
public:
    Service(Repo &repo) : repo{repo} {};

    vector<SourceFile> get_all_source();
    vector<Programmer> get_all_prog();

    int get_nr_already_revised(Programmer &prog);
    int get_nr_not_revised(Programmer &prog);

    bool find_name(std::string name);

    void add_file(std::string name, std::string creator);
    void set_Reviewer(int index, std::string name);
    void set_status(int index, std::string status);
};

#endif //SECONDARY_SERVICE_H

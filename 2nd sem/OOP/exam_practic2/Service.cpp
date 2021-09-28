//
// Created by octat on 6/18/2021.
//

#include "Service.h"

vector<SourceFile> Service::get_all_source() {
    return this->repo.get_all_source();
}

vector<Programmer> Service::get_all_prog() {
    return this->repo.get_all_prog();
}

int Service::get_nr_already_revised(Programmer &prog) {
    int s=0;
    for(auto g:get_all_source())
        if(g.getReviewer()==prog.getName() && g.getStatus()=="revised")
            s++;
        return s;
}

int Service::get_nr_not_revised(Programmer &prog) {
    int s=0;
    for(auto g:get_all_source())
        if(g.getReviewer()==prog.getName() && g.getStatus()=="not_revised")
            s++;
    return s;
}

bool Service::find_name(std::string name) {
    for(auto g:get_all_source())
        if(g.getName()==name)
            return false;
        return true;
}

void Service::add_file(std::string name, std::string creator) {
    SourceFile source{name, "not_revised", creator, ""};
    this->repo.add_repo_source(source);
}

void Service::set_Reviewer(int index, std::string name) {
    this->repo.setReviewer(index, name);
}

void Service::set_status(int index, std::string status) {
    this->repo.setStatus(index, status);
}


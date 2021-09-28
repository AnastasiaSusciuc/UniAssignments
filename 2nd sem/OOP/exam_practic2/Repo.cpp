//
// Created by octat on 6/18/2021.
//

#include "Repo.h"
#include <iostream>

#include <algorithm>
#include <fstream>

using namespace std;


void Repo::add_repo_prog(const Programmer &programmer) {
    if (this->find_repo_prog(programmer) != -1)
        throw std::runtime_error("\nThis item already exists!\n");
    this->programmers.push_back(programmer);
    this->write_file();
}

void Repo::add_repo_source(const SourceFile &source) {
    if (this->find_repo_source(source) != -1)
        throw std::runtime_error("\nThis item already exists!\n");
    this->sources.push_back(source);
    //this->write_file();


}

int Repo::find_repo_prog(const Programmer &prog) {
//    size_t position = std::find(this->programmers.begin(), this->programmers.end(), prog) - this->programmers.begin();
//    if (position < this->programmers.size())
//        return position;
//    return -1;
    for(auto a: programmers)
        if(a.getName()==prog.getName())
            return 0;
        return -1;
}

void Repo::read_file() {
    Programmer programmer{};

    ifstream f("../programmers.txt");
    if(f.fail())
        throw std::exception();

    while(f>>programmer)
    {
        programmers.push_back(programmer);
    }
    f.close();

    SourceFile source;

    ifstream df("../sourcefiles.txt");

    if(df.fail())
        throw std::exception();
    while(df>>source)
    {
        sources.push_back(source);
    }
    df.close();


}

int Repo::find_repo_source(const SourceFile &sourceFile) {
//    size_t position = std::find(this->sources.begin(), this->sources.end(), sourceFile) - this->sources.begin();
//    if (position < this->sources.size())
//        return position;
//    return -1;
    for(auto a: sources)
        if(a.getName()==sourceFile.getName())
            return 0;
    return -1;
}

void Repo::setReviewer(int index, std::string name) {
    sources[index].setReviewer(name);

}

void Repo::setStatus(int index, std::string status) {
    sources[index].setStatus(status);
}


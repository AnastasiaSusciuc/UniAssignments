//
// Created by octat on 6/18/2021.
//
#pragma once
#include "Programmer.h"
#include "SourceFile.h"

#ifndef SECONDARY_REPO_H
#define SECONDARY_REPO_H


class Repo
{
private:
    vector<Programmer> programmers;
    vector<SourceFile> sources;

    void read_file();

    void write_file() {};

//public:
//    struct RepositoryException : public std::exception
//    {
//        const char *what() const throw()
//        {
//            return "Repository Exception!";
//        }
//    };

public:

    Repo() { this->read_file();};

    void add_repo_prog(const Programmer &programmer);
    void add_repo_source(const SourceFile &source);


    int find_repo_prog(const Programmer &prog);
    int find_repo_source(const SourceFile &source);

    vector<Programmer> get_all_prog(){return programmers;}
    vector<SourceFile> get_all_source(){return sources;}

    void setReviewer(int index, std::string name);
    void setStatus(int index, std::string status);



};

#endif //SECONDARY_REPO_H

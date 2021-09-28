//
// Created by octat on 6/18/2021.
//

#include "SourceFile.h"

istream &operator>>(istream &is, SourceFile &prog) {
    std::string line_read;

    getline(is, line_read);
    char d = ';';

    vector<string> a;
    SourceFile::tokenize(line_read, d, a);
    if (a.size() != 4)
        return is;

    prog.setName(a[0].c_str());
    prog.setStatus(a[1].c_str());
    prog.setCreator(a[2].c_str());
    prog.setReviewer(a[3].c_str());

    return is;
}

void SourceFile::tokenize(string &str, char delim, vector<string> &out) {
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

const string &SourceFile::getName() const {
    return name;
}

void SourceFile::setName(const string &name) {
    SourceFile::name = name;
}

const string &SourceFile::getStatus() const {
    return status;
}

void SourceFile::setStatus(const string &status) {
    SourceFile::status = status;
}

const string &SourceFile::getCreator() const {
    return creator;
}

void SourceFile::setCreator(const string &creator) {
    SourceFile::creator = creator;
}

const string &SourceFile::getReviewer() const {
    return reviewer;
}

void SourceFile::setReviewer(const string &reviewer) {
    SourceFile::reviewer = reviewer;
}

std::string SourceFile::toString() {
    return this->getName()+";"+this->getStatus()+";"+this->getCreator()+";"+this->getReviewer();
}

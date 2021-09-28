//
// Created by octat on 6/18/2021.
//

#include "Programmer.h"
#include <stdlib.h>

istream &operator>>(istream &is, Programmer &prog) {
    std::string line_read;

    getline(is, line_read);
    char d = ';';

    vector<string> a;
    Programmer::tokenize(line_read, d, a);
    if (a.size() != 3)
        return is;

    prog.setName(a[0].c_str());
    prog.setRevised(atoi(a[1].c_str()));
    prog.setTotal(atoi(a[2].c_str()));

    return is;
}

void Programmer::tokenize(string &str, char delim, vector<string> &out) {
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

std::string Programmer::toString() {
    return this->getName()+";"+std::to_string(this->getRevised())+";"+std::to_string(this->getTotal());
}

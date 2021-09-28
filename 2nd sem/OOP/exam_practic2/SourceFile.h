//
// Created by octat on 6/18/2021.
//

#ifndef SECONDARY_SOURCEFILE_H
#define SECONDARY_SOURCEFILE_H

#include <iostream>
#include <vector>
using namespace std;

class SourceFile {
private:
    std::string name;
    std::string status;
    std::string creator;
    std::string reviewer;
public:
    SourceFile()=default;
    SourceFile(  std::string name, std::string status, std::string creator, std::string reviewer) : name{name}, status{status}, creator{creator}, reviewer{reviewer} {};
    const string &getName() const;

    void setName(const string &name);

    const string &getStatus() const;

    void setStatus(const string &status);

    const string &getCreator() const;

    void setCreator(const string &creator);

    const string &getReviewer() const;

    void setReviewer(const string &reviewer);

    friend istream& operator>>(istream& is, SourceFile& prog);

    static void tokenize(string &str, char delim, vector<string> &out);

    std::string toString();

};


#endif //SECONDARY_SOURCEFILE_H

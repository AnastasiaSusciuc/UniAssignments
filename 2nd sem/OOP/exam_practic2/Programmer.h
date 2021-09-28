//
// Created by octat on 6/18/2021.
//


#ifndef SECONDARY_PROGRAMMER_H
#define SECONDARY_PROGRAMMER_H

#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Programmer
{
private:
    std::string name;
    int revised;
    int total;
public:
    Programmer(){};
    Programmer(std::string name, int revised, int total) : name{name}, revised{total}, total{total} {};

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Programmer::name = name;
    }

    int getRevised() const {
        return revised;
    }

    void setRevised(int revised) {
        Programmer::revised = revised;
    }

    int getTotal() const {
        return total;
    }

    void setTotal(int total) {
        Programmer::total = total;
    }

    friend istream& operator>>(istream& is, Programmer& prog);

    //friend istream& operator>>(istream& os, Iris& iris);

    std::string toString();

    static void tokenize(string &str, char delim, vector<string> &out);
};



#endif //SECONDARY_PROGRAMMER_H

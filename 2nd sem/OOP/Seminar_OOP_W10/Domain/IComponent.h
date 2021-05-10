//
// Created by susci on 4/27/2021.
//

#ifndef OOP_ICOMPONENT_H
#define OOP_ICOMPONENT_H
#include <string>

struct matrix{
    int number_lines;
    int number_cols;
    int elems[50][50];
};

class IComponent {
public:
    virtual matrix show()=0;
    static std::string print(IComponent*);
};


#endif //OOP_ICOMPONENT_H

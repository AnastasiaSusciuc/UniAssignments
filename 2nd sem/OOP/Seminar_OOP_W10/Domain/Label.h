//
// Created by susci on 4/27/2021.
//

#ifndef OOP_LABEL_H
#define OOP_LABEL_H
#include "BasicComponent.h"
#include <string>

class Label: public BasicComponent {
protected:
    std::string _tag;

public:
    Label(const std::string& );
    virtual matrix show() override;

};


#endif //OOP_LABEL_H

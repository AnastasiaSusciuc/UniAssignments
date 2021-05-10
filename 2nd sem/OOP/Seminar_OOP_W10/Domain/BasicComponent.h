//
// Created by susci on 4/27/2021.
//

#ifndef OOP_BASICCOMPONENT_H
#define OOP_BASICCOMPONENT_H
#include "IBasicComponent.h"

class BasicComponent: public IBasicComponent {

public:
    BasicComponent(int, int, unsigned char);
    virtual matrix show() override;

};


#endif //OOP_BASICCOMPONENT_H

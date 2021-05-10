//
// Created by susci on 4/27/2021.
//

#ifndef OOP_BORDEREDCOMPONENT_H
#define OOP_BORDEREDCOMPONENT_H
#include "IBorderedComponent.h"

class BorderedComponent: public IBorderedComponent {

public:
    BorderedComponent(IBasicComponent*, int, unsigned char);
    virtual matrix show() override;

};


#endif //OOP_BORDEREDCOMPONENT_H

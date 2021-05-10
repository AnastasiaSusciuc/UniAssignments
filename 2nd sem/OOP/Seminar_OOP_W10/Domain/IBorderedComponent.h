//
// Created by susci on 4/27/2021.
//

#ifndef OOP_IBORDEREDCOMPONENT_H
#define OOP_IBORDEREDCOMPONENT_H
#include "IBasicComponent.h"

class IBorderedComponent: public IBasicComponent {
protected:
    IBasicComponent* component;
    int _thickness;
    unsigned char _border_tile;

public:
    IBorderedComponent(IBasicComponent*, int, unsigned char);
    int get_thickness() const;
    unsigned char get_border_tile() const;
    virtual matrix show() = 0;

};


#endif //OOP_IBORDEREDCOMPONENT_H

//
// Created by susci on 4/27/2021.
//

#ifndef OOP_IBASICCOMPONENT_H
#define OOP_IBASICCOMPONENT_H
#include "IComponent.h"

class IBasicComponent:public IComponent {

protected:
    int _width;
    int _height;
    unsigned char _tile;

public:
    IBasicComponent(int, int, unsigned char);
    int get_width() const;
    int get_height() const;
    unsigned char get_tile() const;
    virtual matrix show() = 0;
};


#endif //OOP_IBASICCOMPONENT_H

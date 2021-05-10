//
// Created by susci on 4/27/2021.
//

#ifndef OOP_HORIZONTALLAYOUT_H
#define OOP_HORIZONTALLAYOUT_H
#include "ILayout.h"

class HorizontalLayout:public ILayout {

public:
    HorizontalLayout();
    virtual void addComponent(IBasicComponent*) override;
    virtual matrix show() override;
};


#endif //OOP_HORIZONTALLAYOUT_H

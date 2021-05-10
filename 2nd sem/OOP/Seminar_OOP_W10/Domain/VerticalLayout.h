//
// Created by susci on 4/27/2021.
//

#ifndef OOP_VERTICALLAYOUT_H
#define OOP_VERTICALLAYOUT_H
#include "ILayout.h"

class VerticalLayout : public ILayout {

public:
    VerticalLayout();
    virtual void addComponent(IBasicComponent*) override;
    virtual matrix show() override;
};


#endif //OOP_VERTICALLAYOUT_H

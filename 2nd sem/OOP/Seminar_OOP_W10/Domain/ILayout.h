//
// Created by susci on 4/27/2021.
//

#ifndef OOP_ILAYOUT_H
#define OOP_ILAYOUT_H
#include "IBasicComponent.h"
#include <vector>

class ILayout : public IBasicComponent{

protected:
    std::vector <IBasicComponent*> children;

public:
    ILayout();
    virtual matrix show() = 0;
    virtual void addComponent(IBasicComponent*) = 0;

};


#endif //OOP_ILAYOUT_H

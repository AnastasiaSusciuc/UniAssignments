//
// Created by susci on 4/27/2021.
//

#include "IBorderedComponent.h"
#include <iostream>

IBorderedComponent::IBorderedComponent(IBasicComponent * ibc, int thickness, unsigned char border_tile) :
IBasicComponent(ibc->get_height() + 2 * thickness, ibc->get_width() + 2 * thickness, ibc->get_tile()),
_thickness{thickness},
_border_tile{border_tile},
component{ibc}
{
    std::cout << "HEIGHT " << ibc->get_height() << '\n';
}

int IBorderedComponent::get_thickness() const {
    return this->_thickness;
}

unsigned char IBorderedComponent::get_border_tile() const {
    return this->_border_tile;
}

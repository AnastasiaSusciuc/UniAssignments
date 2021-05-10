//
// Created by susci on 4/27/2021.
//

#include "IBasicComponent.h"

IBasicComponent::IBasicComponent(int height, int width, unsigned char tile) : IComponent(), _height{height}, _width{width}, _tile{tile} {

}

int IBasicComponent::get_width() const {
    return this->_width;
}

int IBasicComponent::get_height() const {
    return this->_height;
}

unsigned char IBasicComponent::get_tile() const {
    return this->_tile;
}

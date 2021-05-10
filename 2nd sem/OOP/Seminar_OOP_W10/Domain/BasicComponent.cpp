//
// Created by susci on 4/27/2021.
//

#include "BasicComponent.h"

matrix BasicComponent::show() {
    matrix m;
    m.number_lines = this->_height;
    m.number_cols = this->_width;
    for (int i = 0; i < m.number_lines; i++)
    {
        for (int j = 0; j < m.number_cols; j++)
        {
            m.elems[i][j] = this->_tile;
        }
    }
    return m;
}

BasicComponent::BasicComponent(int width, int height, unsigned char tile) : IBasicComponent(width, height, tile)
{

}

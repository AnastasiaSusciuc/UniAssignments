//
// Created by susci on 4/27/2021.
//

#include "BorderedComponent.h"

matrix BorderedComponent::show() {

    matrix m{this->component->get_height()+2*this->_thickness,  this->component->get_width()+2*this->_thickness, 0};
    matrix child_m = this->component->show();

    for (int i = 0; i < m.number_lines; i++)
    {
        for (int j = 0; j < m.number_cols; j++)
        {

            if (i < this->_thickness || i >= child_m.number_lines + this->_thickness || j < this->_thickness || j >= child_m.number_cols + this->_thickness)
            {
                m.elems[i][j] = this->_border_tile;
            }
            else
            {
                m.elems[i][j] = child_m.elems[i-this->_thickness][j-this->_thickness];
            }

        }
    }

    return m;
}

BorderedComponent::BorderedComponent(IBasicComponent * ibc, int thickness, unsigned char border_tile) :
IBorderedComponent(ibc, thickness, border_tile){
}

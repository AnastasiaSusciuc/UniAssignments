//
// Created by susci on 4/27/2021.
//

#include "VerticalLayout.h"

VerticalLayout::VerticalLayout() : ILayout() {

}

void VerticalLayout::addComponent(IBasicComponent *ibc) {
    if (this->_width < ibc->get_width())
    {
        this->_width = ibc->get_width();
    }
    this->_height += ibc->get_height();
    this->children.push_back(ibc);
}

matrix VerticalLayout::show() {
    matrix m{this->_height, this->_width, 0};
    matrix child_m;
    int offset = 0;
    int horizontal_offset = 0;

    for (const auto& ch: this->children)
    {
        child_m = ch->show();
        horizontal_offset = (this->_width-child_m.number_cols)/2;

        for (int i = 0; i < child_m.number_lines; i++)
        {
            for (int j = 0; j < child_m.number_cols; j++)
            {
                m.elems[i+offset][j+horizontal_offset] = child_m.elems[i][j];
            }
        }
        offset+=child_m.number_lines;
    }
    return m;
}

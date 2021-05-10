//
// Created by susci on 4/27/2021.
//

#include "HorizontalLayout.h"

HorizontalLayout::HorizontalLayout(): ILayout() {

}

void HorizontalLayout::addComponent(IBasicComponent* ibc) {
    if (this->_height < ibc->get_height())
    {
        this->_height = ibc->get_height();
    }
    this->_width += ibc->get_width();
    this->children.push_back(ibc);
}

matrix HorizontalLayout::show() {
    matrix m{this->_height, this->_width, 0};
    matrix child_m;
    int offset = 0;
    int vert_offset = 0;

    for (const auto& ch: this->children)
    {
        child_m = ch->show();
        vert_offset = (this->_height-child_m.number_lines)/2;

        for (int i = 0; i < child_m.number_lines; i++)
        {
            for (int j = 0; j < child_m.number_cols; j++)
            {
                m.elems[i+vert_offset][j+offset] = child_m.elems[i][j];
            }
        }
        offset+=child_m.number_cols;
    }

    return m;
}

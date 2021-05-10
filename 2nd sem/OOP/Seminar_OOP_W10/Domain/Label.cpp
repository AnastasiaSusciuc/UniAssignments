//
// Created by susci on 4/27/2021.
//

#include "Label.h"

Label::Label(const std::string & tag) : BasicComponent(1, tag.size(), 0), _tag{tag}{

}

matrix Label::show() {
    matrix m;
    m.number_lines = this->_height;
    m.number_cols = this->_width;

    for (int i = 0; i < m.number_cols; i++)
    {
        m.elems[0][i] = this->_tag[i];
    }
    return m;
}

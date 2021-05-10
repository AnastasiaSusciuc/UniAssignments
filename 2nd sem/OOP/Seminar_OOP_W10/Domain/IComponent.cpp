//
// Created by susci on 4/27/2021.
//

#include "IComponent.h"

std::string IComponent::print(IComponent *ic) {
    matrix m = ic->show();
    std::string str = "";
    for (int i = 0; i < m.number_lines; i++)
    {
        for (int j = 0 ; j < m.number_cols; j++)
        {
            str += m.elems[i][j];
        }
        str+='\n';
    }
    return str;
}

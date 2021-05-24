//
// Created by susci on 5/23/2021.
//

#include "Vegetable.h"

#include <utility>

Vegetable::Vegetable(std::string family, std::string name, std::string parts) :
_family(std::move(family)), _name(std::move(name)), _parts(std::move(parts)) {
}

const std::string &Vegetable::getFamily() const {
    return _family;
}

void Vegetable::setFamily(const std::string &family) {
    _family = family;
}

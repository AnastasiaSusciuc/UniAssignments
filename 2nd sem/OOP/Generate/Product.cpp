//
// Created by Tudor Tise on 23/05/2021.
//

#include "Product.h"
#include "string"
#include <vector>
#include <sstream>

Product::Product(const std::string &_category, const std::string &_name, int _quantity) {
    this->category = _category;
    this->name = _name;
    this->quantity = _quantity;
}

const std::string &Product::getCategory() const {
    return category;
}

void Product::setCategory(const std::string &category) {
    Product::category = category;
}

const std::string &Product::getName() const {
    return name;
}

void Product::setName(const std::string &name) {
    Product::name = name;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    Product::quantity = quantity;
}

std::istream &operator>>(std::istream &input, Product &p) {
    std::vector<std::string> tokens;
    std::string token;

    std::string line ;
    getline(input,line);
    std::stringstream tokenStream(line);

    while (getline(tokenStream, token, ',')){
        tokens.push_back(token);
    }

    if (tokens.size() != 3){
        return input;
    } else {
        p.setCategory(tokens[0]);
        p.setName(tokens[1]);
        p.setQuantity(stoi(tokens[2]));
    }
    return input;
}

std::ostream &operator<<(std::ostream &output, const Product &d) {
    output << d.getCategory() << "," << d.getName()
           << "," << d.getQuantity();
    return output;
}

std::string Product::toString() {
    return getCategory() + getName() + std::to_string(getQuantity());
}

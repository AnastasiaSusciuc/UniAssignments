//
// Created by Tudor Tise on 23/05/2021.
//

#ifndef GENERATE_PRODUCT_H
#define GENERATE_PRODUCT_H
#include <iostream>

class Product {
private:
    std::string category;
    std::string name;
    int quantity;
public:
    Product() = default;
    Product(const std::string& _category, const std::string& _name, int _quantity);

    const std::string &getCategory() const;

    void setCategory(const std::string &category);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getQuantity() const;

    void setQuantity(int quantity);

    friend std::ostream &operator<<(std::ostream &output, const Product &);

    friend std::istream &operator>>( std::istream  &input, Product & );

    std::string toString();
};


#endif //GENERATE_PRODUCT_H

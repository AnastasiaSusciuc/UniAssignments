//
// Created by Tudor Tise on 23/05/2021.
//

#include <fstream>
#include "Repo.h"

void Repo::read_from_file_repo() {
    std::ifstream file;
    Product p;
    file.open("products.txt");
    while (file >> p){
        this->add_product(p);
    }
}

void Repo::add_product(const Product &p) {
    this->products.push_back(p);
}

void Repo::delete_from_repo(int pos) {
    this->products.erase(this->products.begin() + pos);
}

std::vector<Product> Repo::get_all() const{
    return this->products;
}

int Repo::get_pos(const std::string& _name) {
    std::vector<Product> all_products = this->get_all();
    int i = 0;
    for (auto p : all_products){
        if (p.getName() == _name)
            return i;
        i++;
    }
    return -1;
}

void Repo::write_to_file() {
    std::ofstream file;
    file.open ("products.txt");
    std::vector<Product> all_products = this->get_all();
    for (auto d : all_products){
        file << d << std::endl;
    }
    file.close();
}

Product Repo::get_product_by_pos_repo(int position) {
    if (position < 0 || position >= products.size())
        throw std::runtime_error("Invalid position");
    return products[position];
}



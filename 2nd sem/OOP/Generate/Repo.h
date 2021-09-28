//
// Created by Tudor Tise on 23/05/2021.
//

#ifndef GENERATE_REPO_H
#define GENERATE_REPO_H
#include <vector>
#include "Product.h"


class Repo {
private:
    std::vector<Product> products;
public:
    Repo() = default;

    void read_from_file_repo();

    void add_product(const Product&);

    void delete_from_repo(int pos);

    std::vector<Product> get_all() const;

    int get_pos(const std::string& _name);

    void write_to_file();

    Product get_product_by_pos_repo(int pos);
};


#endif //GENERATE_REPO_H

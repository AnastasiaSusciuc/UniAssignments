//
// Created by Tudor Tise on 23/05/2021.
//

#include "Service.h"

void Service::read_data_file() {
    this->repo.read_from_file_repo();
}

std::vector<Product> Service::get_products_service() const {
    return this->repo.get_all();
}

void Service::add_product_service(const std::string &_category, const std::string &_name, int _quantity) {
    Product p = Product(_category, _name, _quantity);
    this->repo.add_product(p);
}

void Service::delete_product_service(const std::string &_name) {
    if (this->repo.get_pos(_name) > -1){
        this->repo.delete_from_repo(this->repo.get_pos(_name));
        this->repo.write_to_file();
    } else {
        throw std::exception();
    }
}

Product Service::get_product_by_pos(int pos) {
    return this->repo.get_product_by_pos_repo(pos);
}

std::vector<Product> Service::get_filtered_list(const std::string& _category) const{
    std::vector<Product> filtered;
    std::vector<Product> all = this->get_products_service();

    for (auto& p: all){
        if (p.getCategory() == _category){
            filtered.push_back(p);
        }
    }
    return filtered;
}

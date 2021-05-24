//
// Created by susci on 5/24/2021.
//

#ifndef UNTITLED1_SERVICE_H
#define UNTITLED1_SERVICE_H
#include "Repo.h"
#include <algorithm>
class Service {
private:
    Repo& repo;
public:
    Service(Repo& r): repo(r){};

    void read_data_file() {
        this->repo.read_from_file_repo();
    }

    std::vector<TimeInterval>  get_products_service() const {
        return this->repo.get_all();
    }

//    void add_product_service(const std::string& _category, const std::string& _name, int _quantity);
//
//    void delete_product_service(const std::string& _name);
//
//    Product get_product_by_pos(int pos);
//
    std::vector<TimeInterval> get_filtered_list(int probability) const;
    std::vector<std::string> get_descriptions() const;
};
#endif //UNTITLED1_SERVICE_H

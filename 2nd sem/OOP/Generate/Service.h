//
// Created by Tudor Tise on 23/05/2021.
//

#ifndef GENERATE_SERVICE_H
#define GENERATE_SERVICE_H
#include "Repo.h"

class Service {
private:
    Repo& repo;
public:
    Service(Repo& r): repo(r){};

    void read_data_file();

    std::vector<Product>  get_products_service() const;

    void add_product_service(const std::string& _category, const std::string& _name, int _quantity);

    void delete_product_service(const std::string& _name);

    Product get_product_by_pos(int pos);

    std::vector<Product> get_filtered_list(const std::string& _category) const;
};


#endif //GENERATE_SERVICE_H

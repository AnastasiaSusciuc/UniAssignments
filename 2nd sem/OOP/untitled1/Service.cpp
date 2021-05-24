//
// Created by susci on 5/24/2021.
//

#include "Service.h"

std::vector<TimeInterval> Service::get_filtered_list(int probability) const {
    std::vector<TimeInterval> filtered;
    std::vector<TimeInterval> all = this->get_products_service();

    for (auto& p: all){
        if (p.getPrecipitationProbability() > probability){
            filtered.push_back(p);
        }
    }
    return filtered;
}

std::vector<std::string> Service::get_descriptions() const {
    std::vector<std::string> filtered;
    std::vector<TimeInterval> all = this->get_products_service();

    for (auto& p: all){
        if (std::find(filtered.begin(), filtered.end(), p.getDescription()) == filtered.end()){

            filtered.push_back(p.getDescription());
        }
    }
    return filtered;
}

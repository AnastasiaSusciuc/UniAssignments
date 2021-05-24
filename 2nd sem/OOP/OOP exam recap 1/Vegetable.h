//
// Created by susci on 5/23/2021.
//

#ifndef OOP_EXAM_RECAP_1_VEGETABLE_H
#define OOP_EXAM_RECAP_1_VEGETABLE_H
#include <string>

class Vegetable {
private:
    std::string _family;
    std::string _name;
    std::string _parts;
public:
    Vegetable(std::string  family, std::string  name, std::string  parts);

    const std::string &getFamily() const;

    void setFamily(const std::string &family);

};


#endif //OOP_EXAM_RECAP_1_VEGETABLE_H

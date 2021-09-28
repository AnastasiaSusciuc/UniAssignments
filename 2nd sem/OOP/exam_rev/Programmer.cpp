//
// Created by susci on 6/18/2021.
//

#include "Programmer.h"

const std::string &Programmer::getName() const {
    return name;
}

void Programmer::setName(const std::string &name) {
    Programmer::name = name;
}

int Programmer::getRevisedFiles() const {
    return revised_files;
}

void Programmer::setRevisedFiles(int revisedFiles) {
    revised_files = revisedFiles;
}

int Programmer::getTotalFiles() const {
    return total_files;
}

void Programmer::setTotalFiles(int totalFiles) {
    total_files = totalFiles;
}

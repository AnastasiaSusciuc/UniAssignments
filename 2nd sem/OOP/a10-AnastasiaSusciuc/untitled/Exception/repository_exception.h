//
// Created by susci on 4/11/2021.
//

#ifndef UNTITLED_REPOSITORY_EXCEPTION_H
#define UNTITLED_REPOSITORY_EXCEPTION_H
#include <string>

class RepositoryException: public std::exception {
private:
    std::string messageOfException;
    std::string errorGenerated;

public:
    explicit RepositoryException(std::string messageOfException = "");
    const char* what() const noexcept;
};

#endif //UNTITLED_REPOSITORY_EXCEPTION_H

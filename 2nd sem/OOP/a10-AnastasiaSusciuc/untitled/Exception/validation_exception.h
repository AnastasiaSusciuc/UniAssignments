//
// Created by susci on 4/11/2021.
//

#ifndef UNTITLED_VALIDATION_EXCEPTION_H
#define UNTITLED_VALIDATION_EXCEPTION_H

#include <string>

class ValidationException:  public std::exception {
private:
    std::string messageOfException;
    std::string errorGenerated;

public:
    explicit ValidationException(const std::string& messageOfException = "");
    const char* what() const noexcept;
};

#endif //UNTITLED_VALIDATION_EXCEPTION_H

//
// Created by susci on 4/11/2021.
//

#include "validation_exception.h"
ValidationException::ValidationException(const std::string& messageOfException):messageOfException{messageOfException} {
    errorGenerated = "Validation error: " + messageOfException;
}

const char *ValidationException::what() const noexcept{
    return errorGenerated.c_str();
}
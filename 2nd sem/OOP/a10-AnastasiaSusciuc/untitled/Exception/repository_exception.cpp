//
// Created by susci on 4/11/2021.
//

#include "repository_exception.h"

RepositoryException::RepositoryException(std::string messageOfException): messageOfException{messageOfException} {
    errorGenerated = "FileRepository error: " + messageOfException;
}

const char *RepositoryException::what() const noexcept{
    return errorGenerated.c_str();
}
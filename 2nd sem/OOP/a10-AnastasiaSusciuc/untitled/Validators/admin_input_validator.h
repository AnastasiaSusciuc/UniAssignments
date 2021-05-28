//
// Created by susci on 4/11/2021.
//

#ifndef UNTITLED_ADMIN_INPUT_VALIDATOR_H
#define UNTITLED_ADMIN_INPUT_VALIDATOR_H

#include "../Exception/validation_exception.h"
#include "../Domain/tutorial.h"

class TutorialValidator {
public:
    static void validate_tutorial(const Tutorial& tutorial);
};

#endif //UNTITLED_ADMIN_INPUT_VALIDATOR_H

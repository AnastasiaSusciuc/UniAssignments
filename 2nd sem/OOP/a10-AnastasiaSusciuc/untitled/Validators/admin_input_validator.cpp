//
// Created by susci on 4/11/2021.
//

#include "admin_input_validator.h"

void TutorialValidator::validate_tutorial(const Tutorial &tutorial) {
    const std::string& title = tutorial.get_title();
    const std::string& presenter = tutorial.get_presenter();
    int likes = tutorial.get_number_of_likes();
    std::pair <int, int> duration = tutorial.get_duration();
    const std::string& link = tutorial.get_link();
    std::string errorsList = "";
    if(title.size() < 2)
        errorsList = "Invalid title ";
    if(presenter.size() < 2)
        errorsList += "Invalid presenter ";
    if (likes < 0)
        errorsList += "Invalid likes ";
    if (duration.first < 0 || duration.second < 0 || duration.second > 60)
        errorsList += "Invalid duration ";

    if (!errorsList.empty())
    {
        errorsList+="\n";
        throw ValidationException(errorsList);
    }
}

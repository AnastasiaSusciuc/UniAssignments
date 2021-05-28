//
// Created by susci on 3/20/2021.
//



#include "tutorial.h"
#include <cstring>
#include <utility>

// constructors
Tutorial::Tutorial(std::string title,
                   std::string presenter,
                   std::pair<int, int> duration = std::make_pair(0, 0),
                   int number_of_likes = 0,
                   std::string link = ""): title(std::move(title)),
                                                  presenter(std::move(presenter)),
                                                  duration(std::move(duration)),
                                                  number_of_likes(number_of_likes),
                                                  link(std::move(link)){
}

Tutorial::Tutorial(const Tutorial& tutorial):title{tutorial.title},
                                             presenter{tutorial.presenter},
                                             duration{tutorial.duration},
                                             number_of_likes{tutorial.number_of_likes},
                                             link{tutorial.link}
{}

Tutorial::Tutorial() = default;

// ------ setters -----------------------------------------------------------------------------------------
void Tutorial::set_title(const std::string &tutorial_title) {
    this->title = tutorial_title;
}

void Tutorial::set_presenter(const std::string &tutorial_presenter) {
    this->presenter = tutorial_presenter;
}

void Tutorial::set_duration(const std::pair<int, int> &tutorial_duration) {
    this->duration = tutorial_duration;
}

void Tutorial::set_likes(int tutorial_likes) {
    this->number_of_likes = tutorial_likes;
}

void Tutorial::set_link(const std::string &tutorial_link) {
    this->link = tutorial_link;
}

// ------ getters -----------------------------------------------------------------------------------------
const std::string &Tutorial::get_title() const {
    return this->title;
}

const std::string &Tutorial::get_presenter() const {
    return this->presenter;
}

const std::pair<int, int> &Tutorial::get_duration() const {
    return this->duration;
}

int Tutorial::get_number_of_likes() const {
    return this->number_of_likes;
}

const std::string &Tutorial::get_link() const {
    return this->link;
}

// ------ overload -----------------------------------------------------------------------------------------

bool Tutorial::operator==(const Tutorial &tutorial) const{
    return this->link == tutorial.get_link();
}

void Tutorial::operator=(const Tutorial &tutorial) {
    title = tutorial.get_title();
    presenter = tutorial.get_presenter();
    duration = tutorial.get_duration();
    number_of_likes = tutorial.get_number_of_likes();
    link = tutorial.get_link();
}

bool Tutorial::operator!=(const Tutorial &tutorial) const {
    return !(tutorial == *this);
}

std::ostream &operator<<(std::ostream &outStream, const Tutorial &output_tutorial) {
    outStream << output_tutorial.get_output_form();
    return outStream;
}

std::istream &operator>>(std::istream &inStream, Tutorial &input_tutorial) {

    std::string tutorial_string;
    std::getline(inStream, tutorial_string);
    std::vector <std::string> tokens;

    if (tutorial_string.empty()) {
        return inStream;
    }

    tokens = Tutorial::explode(tutorial_string, ";,");

    input_tutorial.title = tokens[0].substr(6);
    input_tutorial.presenter = tokens[1].substr(11);
    int start = 10;
    std::string minutes;
    while (isdigit(tokens[2][start]))
        minutes+=tokens[2][start++];

    input_tutorial.duration.first = std::stoi(minutes);
    input_tutorial.duration.second = std::stoi(tokens[2].substr(start));
    input_tutorial.number_of_likes = std::stoi(tokens[3].substr(7));
    input_tutorial.link = tokens[4].substr(6);
    input_tutorial.link = input_tutorial.link.substr(0, input_tutorial.link.size());
    return inStream;
}

std::string Tutorial::get_output_form() const {
    std::string finalOutputForm = "Title " + title + ", Presenter " +
            presenter + ", Duration " + std::to_string(duration.first) + " " + std::to_string(duration.second) +
            ", Likes " + std::to_string(number_of_likes) + ", Link " + link + ";";
    return finalOutputForm;
}

std::vector<std::string> Tutorial::explode(const std::string &string_to_explode, const std::string &separators) {
    std::vector<std::string>trash_values = {"Title", "Presenter", "Duration", "Likes", "Link"};
    std::string partial_string;
    std::vector<std::string> exploded_string;

    for (auto iterator: string_to_explode)
    {
        if (iterator != separators[0] && iterator != separators[1])
            partial_string += iterator;
        else
        if ((iterator == separators[0] || iterator == separators[1]) && !partial_string.empty()) {
            exploded_string.push_back(partial_string);
            partial_string = "";
        }
    }
    if (!partial_string.empty())
        exploded_string.push_back(partial_string);

    return exploded_string;
}


Tutorial::~Tutorial() = default;

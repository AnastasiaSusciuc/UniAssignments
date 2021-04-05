//
// Created by susci on 3/20/2021.
//



#include "tutorial.h"

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

// ------ == overload -----------------------------------------------------------------------------------------

bool Tutorial::operator==(const Tutorial &tutorial) {
    return this->link == tutorial.get_link();
}

Tutorial::~Tutorial() = default;

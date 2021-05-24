//
// Created by susci on 5/24/2021.
//

#include "TimeInterval.h"
#include <iostream>

TimeInterval::TimeInterval(int start, int end, int prob, const std::string & desc) : start_hour{start}, end_hour{end}, precipitation_probability{prob}, description{desc} {

}

int TimeInterval::getStartHour() const {
    return start_hour;
}

void TimeInterval::setStartHour(int startHour) {
    start_hour = startHour;
}

int TimeInterval::getEndHour() const {
    return end_hour;
}

void TimeInterval::setEndHour(int endHour) {
    end_hour = endHour;
}

int TimeInterval::getPrecipitationProbability() const {
    return precipitation_probability;
}

void TimeInterval::setPrecipitationProbability(int precipitationProbability) {
    precipitation_probability = precipitationProbability;
}

const std::string &TimeInterval::getDescription() const {
    return description;
}

void TimeInterval::setDescription(const std::string &description) {
    TimeInterval::description = description;
}


std::string TimeInterval::toString() {
    return std::to_string(getStartHour()) + " " + std::to_string(getEndHour()) + " " + std::to_string(getPrecipitationProbability())+
    " " + getDescription() + '\n';
}

std::istream &operator>>(std::istream &input, TimeInterval &p) {
    std::vector<std::string> tokens;
    std::string token;

    std::string line ;
    getline(input,line);
    std::stringstream tokenStream(line);

    while (getline(tokenStream, token, ';')){
        tokens.push_back(token);
    }

    for (auto i:tokens)
        std::cout << i << "* ";


    if (tokens.size() != 4){
        return input;
    } else {
        p.setStartHour(stoi(tokens[0]));
        p.setEndHour(stoi(tokens[1]));
        p.setPrecipitationProbability(stoi(tokens[2]));
        p.setDescription(tokens[3]);
    }
    return input;
}

std::ostream &operator<<(std::ostream &output, const TimeInterval &d) {
    output << d.getStartHour() << "," << d.getEndHour()
           << "," << d.getPrecipitationProbability() << "," << d.getDescription();
    return output;
}
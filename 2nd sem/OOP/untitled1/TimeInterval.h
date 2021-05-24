//
// Created by susci on 5/24/2021.
//

#ifndef UNTITLED1_TIMEINTERVAL_H
#define UNTITLED1_TIMEINTERVAL_H
#include <string>
#include <vector>
#include <sstream>

class TimeInterval {
private:
    int start_hour;
    int end_hour;
    int precipitation_probability;
    std::string description;

public:
    TimeInterval() = default;
    TimeInterval(int, int, int, const std::string&);

    int getStartHour() const;

    void setStartHour(int startHour);

    int getEndHour() const;

    void setEndHour(int endHour);

    int getPrecipitationProbability() const;

    void setPrecipitationProbability(int precipitationProbability);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    friend std::ostream &operator<<(std::ostream &output, const TimeInterval &);

    friend std::istream &operator>>( std::istream  &input, TimeInterval & );

    std::string toString();
};


#endif //UNTITLED1_TIMEINTERVAL_H

//
// Created by susci on 3/20/2021.
//

#ifndef OOP_TUTORIAL_H
#define OOP_TUTORIAL_H
#pragma once
#include <string>


class Tutorial{

private:
    std::string title;
    std::string presenter;
    std::pair <int, int> duration;
    int number_of_likes{};
    std::string link;


public:
    Tutorial(std::string  title,
             std::string  presenter,
             std::pair <int, int>  duration,
             int likes,
             std::string  link);
    Tutorial(const Tutorial& tutorial);
    Tutorial();
    ~Tutorial();
    // ------ setters
    void set_title(const std::string& tutorial_title);
    void set_presenter(const std::string& presenter);
    void set_duration(const std::pair<int, int>& duration);
    void set_likes(int);
    void set_link(const std::string& link);

    // ------ getters
    const std::string& get_title() const;
    const std::string& get_presenter() const;
    const std::pair <int, int>& get_duration() const;
    int get_number_of_likes() const;
    const std::string& get_link() const;

    // ------ operator overload
    bool operator==(const Tutorial &tutorial);
};


#endif //OOP_TUTORIAL_H

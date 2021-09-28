//
// Created by susci on 6/18/2021.
//

#ifndef EXAM_REV_PROGRAMMER_H
#define EXAM_REV_PROGRAMMER_H
#include <string>


class Programmer {

private:
    std::string name;
    int revised_files;
    int total_files;

public:
    const std::string &getName() const;

    int getTotalFiles() const;

    void setTotalFiles(int totalFiles);

    int getRevisedFiles() const;

    void setRevisedFiles(int revisedFiles);

    void setName(const std::string &name);

};

#endif //EXAM_REV_PROGRAMMER_H
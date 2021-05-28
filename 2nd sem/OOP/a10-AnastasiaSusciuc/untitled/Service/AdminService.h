//
// Created by susci on 3/21/2021.
//

#ifndef OOP_ADMINSERVICE_H
#define OOP_ADMINSERVICE_H
#include "../Repository/FileRepository.h"
#include "../Exception/validation_exception.h"
#include "../Validators/admin_input_validator.h"

class AdminService{

private:
    FileRepository& repository;

public:
    AdminService(FileRepository& repository);
    ~AdminService();
    void print_repo_address();
    void add_tutorial_admin_service(const std::string &title,
                             const std::string &presenter,
                             const std::pair<int, int> &duration,
                             int number_of_likes,
                             const std::string &link);
    /*
     * description:  creates a tutorial and adds it into the repository
     *
     * param1:       title - string - the title of the tutorial to be added
     * param2:       presenter - string - the presenter of the tutorial to be added
     * param3:       duration - pair<int, int> - the duration of the tutorial to be added
     * param4:       number_of_likes - int - the number of likes of the tutorial to be added
     * param5:       link - string - the link of the tutorial to be added
     *
     * returns:      0 - the link was not added before, therefore the tutorial was added successfully
     *               1 - the link was added before, therefore the tutorial was not added
     * */
    void remove_tutorial_admin_service(const std::string &link);
    /*
     * description:  creates a tutorial and adds it into the repository
     *
     * param1:       link - string - the link of the tutorial to be removed
     *
     * returns:      -
     * throws:       RepositoryException if there is no tutorial with this link to be erased from the repository
     * */
    Tutorial get_tutorial_by_position_admin_service(int position);
    /*
     * description:  gets a tutorial from a certain position from the repo
     *
     * param1:       position - int - the position of the tutorial to e returned
     *
     * returns:      Tutorial - the entity from the position 'position'
     *
     * throws:       runtime error if the position if negative of greater than the total number of tutorial in the repository
     * */
    void update_tutorial_admin_service(const std::string &tutorial_to_update_link,
                                      const std::string& new_tutorial_title,
                                      const std::string& new_tutorial_presenter,
                                      const std::pair<int, int>& new_duration,
                                      int new_number_of_likes);


    /*
     * description:  creates a tutorial and replaces the old one with the link 'tutorial_to_update_link' with the newly created
     *
     * param1:       tutorial_to_update_link - string - the link of the tutorial to be updated
     * param2:       new_tutorial_title - string - the new title of the tutorial to be updated
     * param3:       duration - pair<int, int> - the duration of the tutorial to be updated
     * param4:       number_of_likes - int - the number of likes of the tutorial to be updated
     * param5:       link - string - the link of the tutorial to be updated
     *
     * returns:      -
     *
     * throws:       RepositoryException if there is no tutorial with this link to be updated in  the repository
     * */
    std::vector<Tutorial> all_tutorials_service();
    /*
     * description:  returns all the tutorials from the service
     *
     * returns:     std::vector<Tutorials>
     * */
    std::vector<Tutorial> tutorials_by_presenter_service(const std::string& substring_presenter);
    /*
     * description:  returns only the tutorials that contain 'substring_presenter' in the presenter field
     *
     * param1:       substring_presenter - std::string
     *
     * returns:     std::vector<Tutorials>
     * */
    int size_repo() const;
    void increase_likes_tutorial_service(const std::string &link);
    /*
     * description:  calls the repo function that increases the number of likes of the tutorial having link 'link
     *
     * param1:       link - std::string
     *
     * returns:
     *
     * throws:       RepositoryException if there is no tutorial with this link to have its number of likes increased
     * */
};

#endif //OOP_ADMINSERVICE_H

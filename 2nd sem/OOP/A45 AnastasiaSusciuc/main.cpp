#include "Tests/tests.h"
#include "Service/AdminService.h"
#include "Service/UserService.h"
#include "UI/UI.h"


int main() {


    Repository all_tutorials_repository;
    WatchListRepository watch_list_repository;

    AdminService admin_service = { all_tutorials_repository };
    UserService user_service = { watch_list_repository };
    UITutorial ui = { admin_service, user_service };
    ui.run();


    return 0;
}

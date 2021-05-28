//
// Created by susci on 5/11/2021.
//

#include "UserGUI.h"

UserGUI::UserGUI(AdminService& adminServ, UserService &userServ) :adminService{adminServ}, userService{userServ}{
    this->mainWindow();
}

void UserGUI::mainWindow() {
    this->setWindowTitle("User");
    this->resize(700, 500);
    auto* MainLayout = new QVBoxLayout{this};

    // display section
    this->watchListWidget = new QListWidget{};
    MainLayout->addWidget(this->watchListWidget);

    // start watching section
    auto* presenterLineEdit = new QLineEdit{};
    presenterLineEdit->setPlaceholderText("Enter presenter");
    substringPresenter = presenterLineEdit;

    auto* watchButton = new QPushButton{"Start watching"};

    QObject::connect(watchButton, &QPushButton::clicked, this, &UserGUI::presentTutorials);

    auto* entryAndButtonLayout = new QHBoxLayout{this}; // layout
    entryAndButtonLayout->addWidget(presenterLineEdit);
    entryAndButtonLayout->addWidget(watchButton);
    MainLayout->addLayout(entryAndButtonLayout);
//    auto* nextButton = new QPushButton{"Next"};
//    MainLayout->addWidget(nextButton);

    // Delete tutorial section
    auto* deleteLayout = new QHBoxLayout{this};
    auto* linkLineEdit = new QLineEdit{};
    deleteLink = linkLineEdit;
    linkLineEdit->setPlaceholderText("Enter link");
    auto* deleteButton = new QPushButton{"Delete tutorial"};
    QObject::connect(deleteButton, &QPushButton::clicked, this, &UserGUI::deleteTutorial);
    deleteLayout->addWidget(linkLineEdit);
    deleteLayout->addWidget(deleteButton);
    MainLayout->addLayout(deleteLayout);
}

void UserGUI::presentTutorials() {
    std::vector <Tutorial> tutorials_by_presenter = adminService.tutorials_by_presenter_service(substringPresenter->text().toLocal8Bit().constData());

    if (tutorials_by_presenter.empty())
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Invalid",  "There are no such tutorials!\n", QMessageBox::Ok);
        return;
    }

    bool flag = false;

    while(true) {

        for (auto & it : tutorials_by_presenter) {
            const std::string& link = it.get_link();
             ShellExecuteA(nullptr, nullptr, "chrome.exe", (it.get_link()).c_str(), nullptr, SW_SHOWMAXIMIZED);

            std::string message = it.get_title() + " by " + it.get_presenter() + "\nDo you want to add the tutorial to the watchlist?";

            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Answer",  QString::fromUtf8(message.c_str()), QMessageBox::Yes| QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                try {
                    userService.add_tutorial_watch_list_user_service(it);
                } catch (RepositoryException& repositoryException) {
                    std::cout << repositoryException.what();
                }
                populateWatchList();
            }

            QMessageBox::StandardButton reply2;
            reply2 = QMessageBox::question(this, "Answer", "Do you want to see another tutorial?", QMessageBox::Yes| QMessageBox::No);
            if (reply2 == QMessageBox::No) {
                flag = true;
              break;
            }
        }
        if (flag)
            break;
    }
}

void UserGUI::populateWatchList() {
    this->watchListWidget->clear();

    QFont f("San Francisco", 14);

    this->watchListWidget->setFont(f);

    std::vector<Tutorial> tutorials_list = userService.all_tutorials_watch_list_service();

    for (auto& t : tutorials_list)
        this->watchListWidget->addItem(QString::fromStdString("\"" + t.get_title() + "\" by " + t.get_presenter() + " link: " + t.get_link()));
}

void UserGUI::deleteTutorial() {

    try{
        userService.remove_tutorial_watch_list_user_service(deleteLink->text().toLocal8Bit().constData());
        populateWatchList();
        std::cout << "Tutorial deleted successfully from the watch list!\n";
    } catch(RepositoryException& repositoryException) {
        std::cout << repositoryException.what();
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Answer", "Did you like the tutorial?", QMessageBox::Yes| QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        adminService.increase_likes_tutorial_service(deleteLink->text().toLocal8Bit().constData());
    }

}

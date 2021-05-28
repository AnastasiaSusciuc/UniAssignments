//
// Created by susci on 5/11/2021.
//

#include "AdminGUI.h"
AdminGUI::AdminGUI(AdminService &adminServ): adminService{adminServ} {

    this->mainWindow();
    this->populateTutorialsList();
    this->connectSignalsAndSlots();
}

void AdminGUI::mainWindow() {
    this->setWindowTitle("Admin");
    this->resize(510, 590);
    auto* MainLayout = new QVBoxLayout{this}; //main layout

    // tutorial list widget
    this->tutorialListWidget = new QListWidget{};
    MainLayout->addWidget(this->tutorialListWidget);

    // line edits
    auto* titleLineEdit = new QLineEdit{};
    title = titleLineEdit;
    auto* presenterLineEdit = new QLineEdit{};
    presenter = presenterLineEdit;
    auto* minutesLineEdit = new QLineEdit{};
    minutes = minutesLineEdit;
    auto* secondsLineEdit = new QLineEdit{};
    seconds = secondsLineEdit;
    auto* likesLineEdit = new QLineEdit{};
    likes = likesLineEdit;
    auto* linkLineEdit = new QLineEdit{};
    link = linkLineEdit;

    auto* tutorialDetails = new QFormLayout{ this };                // layout
    tutorialDetails->addRow("Title", titleLineEdit);
    tutorialDetails->addRow("Presenter", presenterLineEdit);
    tutorialDetails->addRow("Minutes", minutesLineEdit);
    tutorialDetails->addRow("Seconds", secondsLineEdit);
    tutorialDetails->addRow("Likes", likesLineEdit);
    tutorialDetails->addRow("Link", linkLineEdit);
    MainLayout->addLayout(tutorialDetails);

    // buttons add, update, delete
    auto* adminButtonsLayout = new QHBoxLayout {this};              // layout those 3 buttons
    auto* adminAddButton = new QPushButton{"Add"};

    QObject::connect(adminAddButton, &QPushButton::clicked, this, &AdminGUI::addTutorial);

    auto* adminDeleteButton = new QPushButton{"Delete"};
    QObject::connect(adminDeleteButton, &QPushButton::clicked, this, &AdminGUI::deleteTutorial);

    auto* adminUpdateButton = new QPushButton{"Update"};
    QObject::connect(adminUpdateButton, &QPushButton::clicked, this, &AdminGUI::updateTutorial);

    adminButtonsLayout->addWidget(adminAddButton);
    adminButtonsLayout->addWidget(adminDeleteButton);
    adminButtonsLayout->addWidget(adminUpdateButton);

    MainLayout->addLayout(adminButtonsLayout);

    auto* adminChart = new QPushButton{"Show chart"};
    QObject::connect(adminChart, &QPushButton::clicked, this, &AdminGUI::showChart);

    undo = new QPushButton{"Undo"};
    redo = new QPushButton{"Redo"};

    auto* undo_redo_layout = new QVBoxLayout{this};
    undo_redo_layout->addWidget(undo);
    undo_redo_layout->addWidget(redo);
    MainLayout->addLayout(undo_redo_layout);

    auto* chartLayout = new QHBoxLayout{ this };                // layout
    chartLayout->addWidget(adminChart);

    MainLayout->addLayout(chartLayout);
}

void AdminGUI::populateTutorialsList() {

    this->tutorialListWidget->clear();

    QFont f("San Francisco", 14);

    this->tutorialListWidget->setFont(f);

    std::vector<Tutorial> tutorials_list = adminService.all_tutorials_service();
    for (auto& t : tutorials_list)
    {
        this->tutorialListWidget->addItem(QString::fromStdString("\"" + t.get_title() + "\" by " + t.get_presenter()));
    }

    if (this->tutorialListWidget->count() > 0)
        this->tutorialListWidget->setCurrentRow(0);

}

void AdminGUI::connectSignalsAndSlots() {
    QObject::connect(undo, &QPushButton::clicked, this, &AdminGUI::undo_function);
    QObject::connect(redo, &QPushButton::clicked, this, &AdminGUI::redo_function);
    QObject::connect(this->tutorialListWidget, &QListWidget::itemSelectionChanged, [this]() {

        int selectedIndex = this->get_selected();

        if (selectedIndex < 0){
            return;
        }

        Tutorial p  = this->adminService.get_tutorial_by_position_admin_service(selectedIndex);
        this->title->setText(QString::fromStdString(p.get_title()));
        this->presenter->setText(QString::fromStdString(p.get_presenter()));
        this->minutes->setText(QString::fromStdString(std::to_string(p.get_duration().first)));
        this->seconds->setText(QString::fromStdString(std::to_string(p.get_duration().second)));
        this->likes->setText(QString::fromStdString(std::to_string(p.get_number_of_likes())));
        this->link->setText(QString::fromStdString(p.get_link()));
    });
}

void AdminGUI::clearLineEdits() {
    title->clear();
    presenter->clear();
    minutes->clear();
    seconds->clear();
    likes->clear();
    link->clear();
}

void AdminGUI::addTutorial() {

    try{
        adminService.add_tutorial_admin_service(title->text().toStdString(), presenter->text().toStdString(), {std::stoi(minutes->text().toLocal8Bit().constData()), std::stoi(seconds->text().toLocal8Bit().constData())}, std::stoi(likes->text().toLocal8Bit().constData()), link->text().toLocal8Bit().constData());
        this->populateTutorialsList();
        this->clearLineEdits();
    }catch (RepositoryException& repositoryException) {
        QMessageBox::StandardButton reply;
        std::string message = repositoryException.what();
        reply = QMessageBox::warning(this, "Invalid",  QString::fromUtf8(message.c_str()), QMessageBox::Ok);
        std::cout << repositoryException.what();
    } catch (ValidationException& validationException) {
        QMessageBox::StandardButton reply;
        std::string message = validationException.what();
        reply = QMessageBox::warning(this, "Invalid",  QString::fromUtf8(message.c_str()), QMessageBox::Ok);
        std::cout << validationException.what();
    }catch(std::exception &err)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Invalid",  "minutes, seconds, likes should be integers!\n", QMessageBox::Ok);
        std::cout << "minutes, seconds, likes should be integers!\n";
        this->clearLineEdits();
    }
}

void AdminGUI::updateTutorial() {
    try {
        adminService.update_tutorial_admin_service(link->text().toLocal8Bit().constData(), title->text().toStdString(), presenter->text().toStdString(), {std::stoi(minutes->text().toLocal8Bit().constData()), std::stoi(seconds->text().toLocal8Bit().constData())}, std::stoi(likes->text().toLocal8Bit().constData()));
        this->populateTutorialsList();
        this->clearLineEdits();
        // std::cout << "Tutorial updated successfully!\n";
    } catch(RepositoryException& repositoryException) {
        QMessageBox::StandardButton reply;
        std::string message = repositoryException.what();
        reply = QMessageBox::warning(this, "Invalid",  QString::fromUtf8(message.c_str()), QMessageBox::Ok);
        std::cout << repositoryException.what();
    } catch(std::exception &err)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Invalid",  "minutes, seconds, likes should be integers!\n", QMessageBox::Ok);
        std::cout << "minutes, seconds, likes should be integers!\n";
        this->clearLineEdits();
    }
}

void AdminGUI::deleteTutorial() {
    try {
        adminService.remove_tutorial_admin_service(link->text().toLocal8Bit().constData());
        this->populateTutorialsList();
        this->clearLineEdits();
        std::cout << "Tutorial removed successfully!\n";
    } catch(RepositoryException& repositoryException) {
        QMessageBox::StandardButton reply;
        std::string message = repositoryException.what();
        reply = QMessageBox::warning(this, "Invalid",  QString::fromUtf8(message.c_str()), QMessageBox::Ok);
        std::cout << repositoryException.what();
    } catch(std::exception &err)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Invalid",  "minutes, seconds, likes should be integers!\n", QMessageBox::Ok);
        std::cout << "minutes, seconds, likes should be integers!\n";
        this->clearLineEdits();
    }
}

void AdminGUI::showChart() {
    auto chart = new ChartGUI(this->adminService);
    chart->show();
}

void AdminGUI::undo_function() {

}

void AdminGUI::redo_function() {

}

int AdminGUI::get_selected() {
    QModelIndexList index = this->tutorialListWidget->selectionModel()->selectedIndexes();

    if (index.empty()){
        this->title->clear();
        this->presenter->clear();
        this->minutes->clear();
        this->seconds->clear();
        this->likes->clear();
        this->link->clear();
        return -1;
    }

    int selectedIndex = index.at(0).row();
    return selectedIndex;
}

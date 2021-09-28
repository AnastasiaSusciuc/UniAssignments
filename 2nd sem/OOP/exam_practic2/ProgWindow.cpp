//
// Created by octat on 6/18/2021.
//

#include "ProgWindow.h"
#include <QLabel>
#include <QGridLayout>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QRegularExpression>
#include <QObject>
#include <QMessageBox>

void ProgWindow::init_progwindow() {




    this->resize(500,500);
    this->setWindowTitle(QString::fromStdString(prog.getName()));
    this->label = new QLabel{ "HELLO" };

    QWidget *central_widget = new QWidget;
    QGridLayout *grid_layout = new QGridLayout;

    central_widget->setLayout(grid_layout);
    //grid_layout->addWidget(label, 0, 0, 2, 1);

    this->tablemodel = new SourcefileTableModel{ctrl.get_all_source()};
    this->table = new QTableView{};
    table->sortByColumn(3, Qt::AscendingOrder);
    table->setSortingEnabled(true);
    this->table->setModel(tablemodel);

    QSortFilterProxyModel* proxyModel =
            new QSortFilterProxyModel{};
    proxyModel->setSourceModel(tablemodel);
    this->table->setSortingEnabled(true);


    //ui.genesTableView->setAlternatingRowColors(true); // use this if the background role is not used !
    proxyModel->setFilterKeyColumn(0);

    table->setModel(proxyModel);

    // force the columns to resize, according to the size of their contents
    table->resizeColumnsToContents();
    // hide the vertical header
    //ui.genesTableView->verticalHeader()->hide();

    grid_layout->addWidget(table,0,0,1,2);

    this->already_revised = new QLabel{"Already revised:"};
    this->left_to_revise = new QLabel{"Left to revise: "};
    this->already_revised_edit = new QLineEdit{};
    //this->already_revised_edit->setFixedWidth(150);
    this->left_to_revise_edit = new QLineEdit{};

    this->already_revised_edit->setText(QString::fromStdString(to_string(ctrl.get_nr_already_revised(prog))));
    this->left_to_revise_edit->setText(QString::fromStdString(to_string(ctrl.get_nr_not_revised(prog))));

    this->already_revised->setBuddy(already_revised_edit);
    this->left_to_revise->setBuddy(left_to_revise_edit);

    this->added_file_label = new QLabel{"Name of file:"};
    this->added_file_edit= new QLineEdit{};
    this->added_file_label->setBuddy(added_file_edit);

    this->errors=new QLineEdit{};

    this->add_button = new QPushButton{"Add file"};

    this->revise=new QPushButton{"Revise"};

    grid_layout->addWidget(this->added_file_label, 1, 0, 1,1);
    grid_layout->addWidget(this->added_file_edit, 1, 1, 1,1);
    grid_layout->addWidget(this->add_button, 2, 1, 1,1);


    grid_layout->addWidget(this->already_revised, 3, 0, 1,1);
    grid_layout->addWidget(this->left_to_revise, 4, 0, 1,1);
    grid_layout->addWidget(this->already_revised_edit, 3, 1, 1, 1);
    grid_layout->addWidget(this->left_to_revise_edit, 4, 1, 1, 1);
    grid_layout->addWidget(this->errors, 5, 1, 1, 1);
    grid_layout->addWidget(this->revise, 6, 1, 1, 1);

    //if(this->add_button->)
    this->connect();

    this->setCentralWidget(central_widget);

}

void ProgWindow::connect() {
    QObject::connect(this->add_button, &QPushButton::clicked, this, &ProgWindow::connectAdd);
    QObject::connect(this->revise, &QPushButton::clicked, this, &ProgWindow::pressed);
//    QItemSelectionModel *selectionModel = table->selectionModel();
//    QObject::connect(selectionModel, &QItemSelectionModel::selectionChanged,
//            this, &ProgWindow::pressed);

}

void ProgWindow::connectAdd() {
    std::string newfile = this->added_file_edit->text().toStdString();
    cout<<newfile;
    if(newfile=="") {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Invalid", "File is empty!!\n", QMessageBox::Ok);
        return;
    }
        //this->errors->setText("File is empty");
    if(!ctrl.find_name(newfile)) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Invalid", "Already exists!\n", QMessageBox::Ok);
        return;
    }
    this->ctrl.add_file(newfile, prog.getName());

    for(auto g: window)
        g->update_table();
    //this->update_table();
}

void ProgWindow::update_table()
{
    vector<SourceFile> sources = this->ctrl.get_all_source();
    this->tablemodel->update(sources);
}

void ProgWindow::update_table_no_extra()
{
    vector<SourceFile> sources = this->ctrl.get_all_source();
    this->tablemodel->update_no_extra(sources);
}

void ProgWindow::pressed() {
    const QModelIndex index = table->selectionModel()->currentIndex();
    SourceFile source = this->ctrl.get_all_source()[index.row()];
    if(source.getStatus()=="revised")
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Invalid", "Item is revised!!!!!!!\n", QMessageBox::Ok);
        return;
    }
    if(source.getCreator()==prog.getName())
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Invalid", "Same creator\n", QMessageBox::Ok);
        return;
    }
   ctrl.set_status(index.row(), "revised");
    ctrl.set_Reviewer(index.row(), prog.getName());
    for(auto g: window)
        g->update_table_no_extra();
    this->already_revised_edit->setText(QString::fromStdString(to_string(ctrl.get_nr_already_revised(prog))));
    this->left_to_revise_edit->setText(QString::fromStdString(to_string(ctrl.get_nr_not_revised(prog))));
    if(ctrl.get_nr_not_revised(prog)==0)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, "Invalid", "Bravo ba\n", QMessageBox::Ok);
        return;
    }
    this->statisticWindow->update();
}

void update();

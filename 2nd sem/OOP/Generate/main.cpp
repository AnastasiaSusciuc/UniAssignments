#include <QApplication>
#include <QPushButton>

#include "Repo.h"
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo r;
    Service s = Service(r);
    s.read_data_file();

    GUI* g = new GUI(s);

    return a.exec();
}

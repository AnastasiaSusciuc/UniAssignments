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
    std::vector <TimeInterval> all = s.get_products_service();
//    for (auto i: all)
//        std::cout << i.toString() << '\n';

    GUI* g = new GUI(s);

    return a.exec();
}

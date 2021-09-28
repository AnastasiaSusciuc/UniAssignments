#include <QApplication>
#include <QPushButton>

#include "Repo.h"
#include "Service.h"
#include "GUI.h"

int main(int argc, char **argv)
{
// QApplication app (argc, argv);
//
// QPushButton button ("Hello world !");
// button.show();
//
// return app.exec();

QApplication app (argc, argv);
 Repo repo{};
 Service service{repo};
 GUI gui{service};
 gui.initGUI();
 return app.exec();

// vector<Programmer> progs = service.get_all_prog();
// for(auto a:progs)
// {
//     cout<<a.toString()<<endl;
// }
//    vector<SourceFile> sources = service.get_all_source();
//    for(auto a:sources)
//    {
//        cout<<a.toString()<<endl;
//    }
//    return 0;
}
//
// Created by octat on 6/18/2021.
//

#include "GUI.h"

void GUI::initGUI() {

    this->statisticWindow=new StatisticWindow{ctrl};

    for(int i=0;i<progs.size();i++)
    {
        this->windowList.push_back(new ProgWindow{progs[i], ctrl, windowList, statisticWindow});
        this->windowList[i]->show();
    }
    this->statisticWindow->show();

}

void GUI::update_all() {
    cout<<"OK";

}



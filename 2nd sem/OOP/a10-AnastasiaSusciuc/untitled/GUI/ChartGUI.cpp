//
// Created by susci on 5/15/2021.
//

#include "ChartGUI.h"

ChartGUI::ChartGUI(AdminService &adminServ) : adminService{adminServ} {
    this->mainWindow();
}

void ChartGUI::mainWindow() {
    this->setWindowTitle("Statistics");
    this->resize(600, 600);

    auto* series = new QPieSeries();

    std::map<std::string, int> slices = get_every_presenter_number_of_tutorials();
    int number_tutorials = adminService.size_repo();

    auto** slices_label = new QPieSlice*[slices.size()+4];

    int cnt=0;
    for (const auto& slice: slices)
    {
        series->append(QString::fromStdString(slice.first), (double)slice.second/number_tutorials);
        slices_label[cnt] = series->slices().at(cnt);
        slices_label[cnt]->setLabelVisible();
        cnt++;
    }


    // Create the chart widget
    auto *chart = new QChart();

    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("How many tutorials has each presenter");
    chart->legend()->hide();

    // Used to display the chart
    auto *chartView = new QChartView(chart);
    chartView->setWindowTitle("Statistics");
    chartView->setRenderHint(QPainter::Antialiasing);

    auto vLayout = new QVBoxLayout();
    this->setLayout(vLayout);
    vLayout->addWidget(chartView);
//    chartView->show();
}

std::map<std::string, int> ChartGUI::get_every_presenter_number_of_tutorials() {
    std::map<std::string, int> slices;
    std::vector <Tutorial> all_tutorials = adminService.all_tutorials_service();

    for (const auto& tutorial:all_tutorials)
    {
        if (slices.find(tutorial.get_presenter()) != slices.end()) slices[tutorial.get_presenter()]++;
        else
            slices.insert({tutorial.get_presenter(), 1});
    }

    return slices;
}

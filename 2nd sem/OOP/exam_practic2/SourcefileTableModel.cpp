//
// Created by octat on 6/18/2021.
//

#include "SourcefileTableModel.h"
#include <Qbrush>
#include <QFont>
int SourcefileTableModel::rowCount(const QModelIndex &parent) const {
    return sources.size();
}

int SourcefileTableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant SourcefileTableModel::data(const QModelIndex &index, int role) const {
    int row=index.row();
    int col=index.column();

    if (role == Qt::FontRole && this->sources[row].getStatus() == "not_revised") { // First column items are bold.
        QFont font{"Verdana", 15};
        font.setBold(true);
        return font;
    }

    if(role==Qt::BackgroundRole) {
        if (this->sources[row].getStatus() == "revised") return QBrush(Qt::green);
//        if (this->flowers[row].getType() == "Iris-versicolor") return QBrush(Qt::yellow);
//        if (this->flowers[row].getType() == "Iris-virginica") return QBrush(Qt::blue);
    }
    if(role==Qt::DisplayRole) {
        if (col == 0) return QString::fromStdString(this->sources[row].getName());
        if (col == 1) return QString::fromStdString(this->sources[row].getStatus());
        if (col == 2) return QString::fromStdString(this->sources[row].getCreator());
        if (col == 3) return QString::fromStdString(this->sources[row].getReviewer());

    }
    return QVariant();
}
QVariant SourcefileTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if(orientation==Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("Name");
                case 1:
                    return QString("Status+");
                case 2:
                    return QString("Creator");
                case 3:
                    return QString("Reviewer");
            }
        }

    }
    return QVariant();
}


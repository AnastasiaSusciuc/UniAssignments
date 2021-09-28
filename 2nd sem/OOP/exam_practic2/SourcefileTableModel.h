//
// Created by octat on 6/18/2021.
//

#ifndef SECONDARY_SOURCEFILETABLEMODEL_H
#define SECONDARY_SOURCEFILETABLEMODEL_H

#include <QAbstractTableModel>
#include "SourceFile.h"
#include <QSortFilterProxyModel>

class SourcefileTableModel: public QAbstractTableModel
{
    Q_OBJECT
private:
    vector<SourceFile> sources;

public:
    explicit SourcefileTableModel(vector<SourceFile> sources) : sources{sources} {};

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void update(std::vector<SourceFile> input){

        if(sources.size()>0) sources.clear();
        beginInsertRows({}, sources.size(), sources.size());
        for (auto&& i: input)
            sources.push_back(i);
        endInsertRows();
    };
    void update_no_extra(std::vector<SourceFile> input){

        if(sources.size()>0) sources.clear();
        beginInsertRows({}, sources.size(), sources.size());
        for (auto&& i: input)
            sources.push_back(i);
        endInsertRows();
    };

};

#endif //SECONDARY_SOURCEFILETABLEMODEL_H

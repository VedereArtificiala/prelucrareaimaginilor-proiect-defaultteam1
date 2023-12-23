#ifndef IMAGEPROCESSINGLIST_H
#define IMAGEPROCESSINGLIST_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>

#include "imageprocessingstep.h"

class ImageProcessingList : public QAbstractListModel {
    Q_OBJECT
public:
    explicit ImageProcessingList(QObject *parent = nullptr);
    ~ImageProcessingList();

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    qsizetype length();
    ImageProcessingStep* at(qsizetype i);

    Q_INVOKABLE void deleteStep(qsizetype at);
    Q_INVOKABLE void addStep(QString type);

private:
    QList<ImageProcessingStep *> m_steps = QList<ImageProcessingStep *>();
};

#endif // IMAGEPROCESSINGLIST_H

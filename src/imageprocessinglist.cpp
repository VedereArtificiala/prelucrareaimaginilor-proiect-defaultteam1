#include "imageprocessinglist.h"

#include "windowbinarizationstep.h"
#include "binarizationstep.h"

ImageProcessingList::ImageProcessingList(QObject *parent): QAbstractListModel{parent} {
}

ImageProcessingList::~ImageProcessingList() {
    for ( int i = 0; i < m_steps.length(); i++ ) {
        delete m_steps.at(i);
    }

    m_steps.clear();
}

int ImageProcessingList::rowCount(const QModelIndex &parent) const {
    return m_steps.size();
}

QVariant ImageProcessingList::data(const QModelIndex &index, int role) const {
    // regardless of role, get data at specified row of the index
    return QVariant::fromValue(m_steps.at(index.row()));
}

qsizetype ImageProcessingList::length() {
    return m_steps.length();
}

ImageProcessingStep *ImageProcessingList::at(qsizetype i) {
    return m_steps.at(i);
}

void ImageProcessingList::deleteStep(qsizetype at) {
    beginRemoveRows(QModelIndex(), at, at);
    ImageProcessingStep* s = m_steps.at(at);
    m_steps.removeAt(at);
    endRemoveRows();
    delete s;
}

void ImageProcessingList::addStep(QString type) {
    beginInsertRows(QModelIndex(), m_steps.length(), m_steps.length());

    if ( type == "winbin" ) {
        m_steps.append(new WindowBinarizationStep());
    } else if ( type == "bin" ) {
        m_steps.append(new BinarizationStep());
    }

    endInsertRows();
}

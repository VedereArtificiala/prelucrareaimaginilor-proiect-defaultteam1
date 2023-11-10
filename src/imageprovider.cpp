#include "imageprovider.h"

ImageProvider::ImageProvider(QString path, QObject *parent): QObject{parent} {
    m_originalImagePath = path;

    m_originalImage = QImage(path).scaled(300, 300);
    m_finalImage = QImage(path).scaled(300, 300);
}

const QImage &ImageProvider::originalImage() const {
    return m_originalImage;
}

void ImageProvider::setOriginalImage(const QImage &newImage) {
    m_originalImage = newImage;
    emit originalImageChanged();
}

const QImage &ImageProvider::finalImage() const {
    return m_finalImage;
}

void ImageProvider::setFinalImage(const QImage &newImage) {
    m_finalImage = newImage;
    emit finalImageChanged();
}

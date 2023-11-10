#include "customimage.h"

CustomImage::CustomImage(QQuickItem *parent) : QQuickPaintedItem(parent), m_image{} {
}

void CustomImage::setImage(const QImage &newImage) {
    m_image = newImage;

    update();
}

void CustomImage::paint(QPainter *painter) {
    painter->drawImage(0, 0, m_image);
}

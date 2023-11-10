#ifndef CUSTOMIMAGE_H
#define CUSTOMIMAGE_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QImage>

/**
 * @brief A 'dumb' class which acts as an intermediate between QML and other image providers.
 */
class CustomImage : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(QImage image MEMBER m_image WRITE setImage)

public:
    CustomImage(QQuickItem *parent = nullptr);

    void setImage(const QImage &newImage);

    void paint(QPainter *painter) override;

private:
    QImage m_image;
};

#endif // CUSTOMIMAGE_H

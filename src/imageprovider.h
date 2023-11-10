#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QObject>
#include <QImage>
#include <QtDebug>

class ImageProvider : public QObject {
    Q_OBJECT

    Q_PROPERTY(QImage originalImage
               MEMBER m_oringialImage
               READ originalImage
               WRITE setOriginalImage
               NOTIFY originalImageChanged)

    Q_PROPERTY(QImage finalImage
               MEMBER m_finalImage
               READ finalImage
               NOTIFY finalImageChanged)

public:
    ImageProvider(QString path, QObject *parent = nullptr);

    ImageProvider &operator=(const ImageProvider &i) {
        this->m_originalImagePath = i.m_originalImagePath;
        this->m_originalImage = i.m_originalImage;
        this->m_finalImage = i.m_finalImage;

        return *this;
    }

    const QImage &originalImage() const;
    void setOriginalImage(const QImage &newImage);
    const QImage &finalImage() const;
    void setFinalImage(const QImage &newImage);

signals:
    void originalImageChanged();
    void finalImageChanged();

private:
    QString m_originalImagePath;
    QImage m_originalImage;
    QImage m_finalImage;
};

#endif // IMAGEPROVIDER_H

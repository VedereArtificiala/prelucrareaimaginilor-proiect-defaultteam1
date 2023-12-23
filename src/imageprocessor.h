#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>

#include "imageprovider.h"
#include "imageprocessinglist.h"

class ImageProcessor : public QObject {
    Q_OBJECT

    Q_PROPERTY(ImageProcessingList* steps
               MEMBER m_steps
               READ steps
               WRITE setSteps
               NOTIFY stepsChanged)

    Q_PROPERTY(ImageProvider* provider
               MEMBER m_provider
               READ provider
               NOTIFY providerChanged)

public:
    explicit ImageProcessor(QObject *parent = nullptr);
    ~ImageProcessor();

    ImageProvider *provider();

    Q_INVOKABLE void processImage();

    ImageProcessingList *steps() const;
    void setSteps(ImageProcessingList *newSteps);

signals:
    void providerChanged();

    void stepsChanged();

private:
    ImageProvider *m_provider = nullptr;
    ImageProcessingList *m_steps = nullptr;
};

#endif // IMAGEPROCESSOR_H

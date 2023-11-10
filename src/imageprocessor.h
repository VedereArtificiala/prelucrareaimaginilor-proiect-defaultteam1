#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>

#include "imageprovider.h"

class ImageProcessor : public QObject {
    Q_OBJECT

    Q_PROPERTY(ImageProvider* provider
               MEMBER m_provider
               READ provider
               NOTIFY providerChanged)

    Q_PROPERTY(int binarizationThreshold
               MEMBER m_binarizationThreshold
               READ binarizationThreshold
               WRITE setBinarizationThreshold
               NOTIFY binarizationThresholdChanged
               )

    Q_PROPERTY(bool binarizationEnabled
               MEMBER m_binarizationEnabled
               READ binarizationEnable
               WRITE setBinarizationEnabled
               NOTIFY binarizationEnabledChanged
               )

public:
    explicit ImageProcessor(QObject *parent = nullptr);
    ~ImageProcessor();

    ImageProvider *provider();

    Q_INVOKABLE void processImage();

    int binarizationThreshold() const;
    void setBinarizationThreshold(int newBinarizationThreshold);

    bool binarizationEnable() const;
    void setBinarizationEnabled(bool newBinarizationEnabled);

signals:
    void providerChanged();

    void binarizationThresholdChanged();

    void binarizationEnabledChanged();

private:
    ImageProvider *m_provider = nullptr;
    int m_binarizationThreshold = 0;
    bool m_binarizationEnabled = false;
};

#endif // IMAGEPROCESSOR_H

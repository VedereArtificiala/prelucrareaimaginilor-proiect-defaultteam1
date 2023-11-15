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

    Q_PROPERTY(int brightnessValue
               MEMBER m_brightnessValue
               READ brightnessValue
               WRITE setBrightnessValue
               NOTIFY brightnessValueChanged)

    Q_PROPERTY(bool brightnessEnabled
               MEMBER m_brightnessEnabled
               READ brightnessEnabled
               WRITE setBrightnessEnabled
               NOTIFY brightnessEnabledChanged)

    Q_PROPERTY(bool outlineEdgesEnabled
               MEMBER m_outlineEdgesEnabled
               READ outlineEdgesEnabled
               WRITE setOutlineEdgesEnabled
               NOTIFY outlineEdgesEnabledChanged)

public:
    explicit ImageProcessor(QObject *parent = nullptr);
    ~ImageProcessor();

    ImageProvider *provider();

    Q_INVOKABLE void processImage();

    int binarizationThreshold() const;
    void setBinarizationThreshold(int newBinarizationThreshold);

    bool binarizationEnable() const;
    void setBinarizationEnabled(bool newBinarizationEnabled);

    int brightnessValue() const;
    void setBrightnessValue(int newBrightnessValue);

    bool brightnessEnabled() const;
    void setBrightnessEnabled(bool newBrightnessEnabled);

    bool outlineEdgesEnabled() const;
    void setOutlineEdgesEnabled(bool newOutlineEdgesEnabled);

signals:
    void providerChanged();

    void binarizationThresholdChanged();

    void binarizationEnabledChanged();

    void brightnessValueChanged();

    void brightnessEnabledChanged();

    void outlineEdgesEnabledChanged();

private:
    ImageProvider *m_provider = nullptr;
    int m_binarizationThreshold = 128;
    bool m_binarizationEnabled = false;
    int m_brightnessValue = 0;
    bool m_brightnessEnabled = false;
    bool m_outlineEdgesEnabled = false;
};

#endif // IMAGEPROCESSOR_H

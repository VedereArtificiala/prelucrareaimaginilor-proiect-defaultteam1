#include "imageprocessor.h"
#include "Tools.h"
#include "Image_Processing.h"

ImageProcessor::ImageProcessor(QObject *parent): QObject{parent} {
    m_provider = new ImageProvider("/Users/tudor/Desktop/testcellsegm.jpg");
}

ImageProcessor::~ImageProcessor() {
    delete m_provider;
}

ImageProvider *ImageProcessor::provider() {
    return m_provider;
}

void ImageProcessor::processImage() {
    int w = m_provider->originalImage().width();
    int h = m_provider->originalImage().height();

    uint8_t *src = NULL;
    uint8_t *dest = NULL;

    src = Tools::readImageGray8(m_provider->originalImage());

    if ( m_binarizationEnabled ) {
        ImageProcessing::binarize(src, w, h, dest, m_binarizationThreshold);
        swap(src, dest);
    }

    if ( m_brightnessEnabled ) {
        ImageProcessing::changeLuminosityImage(src, w, h, dest, m_brightnessValue);
        swap(src, dest);
    }

    if ( m_outlineEdgesEnabled ) {
        ImageProcessing::sobelOutline(src, w, h, dest);
        swap(src, dest);
    }

    QImage finalImage = Tools::imageGray8FromArray(src, w, h);
    m_provider->setFinalImage(finalImage);

    if ( src )
        delete[] src;

    if ( dest )
        delete[] dest;
}

int ImageProcessor::binarizationThreshold() const {
    return m_binarizationThreshold;
}

void ImageProcessor::setBinarizationThreshold(int newBinarizationThreshold) {
    if (m_binarizationThreshold == newBinarizationThreshold)
        return;
    m_binarizationThreshold = newBinarizationThreshold;
    processImage();
    emit binarizationThresholdChanged();
}

bool ImageProcessor::binarizationEnable() const {
    return m_binarizationEnabled;
}

void ImageProcessor::setBinarizationEnabled(bool newBinarizationEnabled) {
    if (m_binarizationEnabled == newBinarizationEnabled)
        return;
    m_binarizationEnabled = newBinarizationEnabled;
    processImage();
    emit binarizationEnabledChanged();
}

int ImageProcessor::brightnessValue() const {
    return m_brightnessValue;
}

void ImageProcessor::setBrightnessValue(int newBrightnessValue) {
    if (m_brightnessValue == newBrightnessValue)
        return;
    m_brightnessValue = newBrightnessValue;
    processImage();
    emit brightnessValueChanged();
}

bool ImageProcessor::brightnessEnabled() const {
    return m_brightnessEnabled;
}

void ImageProcessor::setBrightnessEnabled(bool newBrightnessEnabled) {
    if (m_brightnessEnabled == newBrightnessEnabled)
        return;
    m_brightnessEnabled = newBrightnessEnabled;
    processImage();
    emit brightnessEnabledChanged();
}

bool ImageProcessor::outlineEdgesEnabled() const {
    return m_outlineEdgesEnabled;
}

void ImageProcessor::setOutlineEdgesEnabled(bool newOutlineEdgesEnabled) {
    if (m_outlineEdgesEnabled == newOutlineEdgesEnabled)
        return;
    m_outlineEdgesEnabled = newOutlineEdgesEnabled;
    processImage();
    emit outlineEdgesEnabledChanged();
}

#include "imageprocessor.h"
#include "Tools.h"
#include "Image_Processing.h"

ImageProcessor::ImageProcessor(QObject *parent): QObject{parent} {
    m_provider = new ImageProvider("/Users/tudor/Nextcloud/Facultate_An3_Sem1/Prelucrarea_Imaginilor/PIApp/Images/lena512.bmp");
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

    uint8_t *image = Tools::readImageGray8(m_provider->originalImage());

    uint8_t *binarized = ImageProcessing::binarize(image, w, h, m_binarizationThreshold);

    QImage finalImage = Tools::imageGray8FromArray(binarized, w, h);
    m_provider->setFinalImage(finalImage);

    delete[] binarized;
    delete[] image;
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

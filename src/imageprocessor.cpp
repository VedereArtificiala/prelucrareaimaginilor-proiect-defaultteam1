#include "imageprocessor.h"
#include "Tools.h"
#include "Image_Processing.h"

ImageProcessor::ImageProcessor(QObject *parent): QObject{parent} {
    m_provider = new ImageProvider("/Users/tudor/Desktop/test.jpg");
    m_steps = new ImageProcessingList();
}

ImageProcessor::~ImageProcessor() {
    delete m_provider;
    delete m_steps;
}

ImageProvider *ImageProcessor::provider() {
    return m_provider;
}

ImageProcessingList *ImageProcessor::steps() const {
    return m_steps;
}

void ImageProcessor::setSteps(ImageProcessingList *newSteps) {
    if (m_steps == newSteps)
        return;
    m_steps = newSteps;
    emit stepsChanged();
}

void ImageProcessor::processImage() {
    int w = m_provider->originalImage().width();
    int h = m_provider->originalImage().height();

    uint8_t *src = NULL;
    uint8_t *dest = NULL;

    src = Tools::readImageGray8(m_provider->originalImage());

    for ( int i = 0; i < m_steps->length(); i++ ) {
        m_steps->at(i)->applyProcessing(src, dest, w, h);
        swap(src, dest);
    }

    QImage finalImage = Tools::imageGray8FromArray(src, w, h);
    m_provider->setFinalImage(finalImage);

    if ( src )
        delete[] src;

    if ( dest )
        delete[] dest;
}

#include "imageprocessor.h"
#include "Tools.h"
#include "Image_Processing.h"

ImageProcessor::ImageProcessor(QObject *parent): QObject{parent} {
    m_provider = new ImageProvider("/Users/tudor/Desktop/steatozahepatica/-1 FNP-LEB H-25471-08/-1 FNP-LEB H-25471-08_Region 011_FOV 01073.jpg");

    m_steps = new ImageProcessingList();
    m_steps->addStep("noisered");
    m_steps->addStep("norm");
    m_steps->addStep("luminosity");
    m_steps->addStep("bin");
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

    if ( m_askedForDiagnosis ) {
        calculateDiagnosis(src, w, h);
        m_provider->setFinalImage(m_diagnosisResult.finalImage); // TODO: use finalImage from diagnosisResult resulted from calculateDiagnosis
    } else
        m_provider->setFinalImage(Tools::imageGray8FromArray(src, w, h));

    if ( src )
        delete[] src;

    if ( dest )
        delete[] dest;
}

void ImageProcessor::calculateDiagnosis(unsigned char *src, int w, int h) {
    cv::Mat matSrc = cv::Mat(h, w, CV_8UC1, src);
    m_diagnosisResult.result = ImageProcessing::processBinaryImage(matSrc, m_diagnosisResult.finalImage, 1500);
    emit diagnosisResultChanged();
}

bool ImageProcessor::askedForDiagnosis() const {
    return m_askedForDiagnosis;
}

void ImageProcessor::setAskedForDiagnosis(bool newAskedForDiagnosis) {
    if (m_askedForDiagnosis == newAskedForDiagnosis)
        return;
    m_askedForDiagnosis = newAskedForDiagnosis;
    emit askedForDiagnosisChanged();
}

const DiagnosisResult &ImageProcessor::diagnosisResult() const {
    return m_diagnosisResult;
}

void ImageProcessor::setDiagnosisResult(const DiagnosisResult &newDiagnosis) {
    m_diagnosisResult = newDiagnosis;
    emit diagnosisResultChanged();
}

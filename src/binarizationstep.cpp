#include "binarizationstep.h"
#include "Image_Processing.h"

BinarizationStep::BinarizationStep(QObject *parent): ImageProcessingStep{parent} {
    m_name = "Binarization";

    threshold.setName("Threhsold");
    threshold.setMinValue(0);
    threshold.setCurrentValue(230);
    threshold.setMaxValue(255);
    m_values.append(&threshold);
}

void BinarizationStep::applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) {
    ImageProcessing::binarize(src, dest, w, h, threshold.getCurrentValue());
}

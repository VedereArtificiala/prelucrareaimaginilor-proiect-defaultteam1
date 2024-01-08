#include "windowbinarizationstep.h"
#include "Image_Processing.h"

WindowBinarizationStep::WindowBinarizationStep(QObject *parent): ImageProcessingStep{parent} {
    m_name = "Window Binarization";

    m_thresholdLeft.setName("Threshold Left");
    m_thresholdLeft.setMinValue(0);
    m_thresholdLeft.setMaxValue(255);
    m_thresholdLeft.setCurrentValue(100);
    m_values.append(&m_thresholdLeft);

    m_thresholdRight.setName("Threshold Right");
    m_thresholdRight.setMinValue(0);
    m_thresholdRight.setMaxValue(255);
    m_thresholdRight.setCurrentValue(200);
    m_values.append(&m_thresholdRight);
}

void WindowBinarizationStep::applyProcessing(unsigned char* src, unsigned char*& dest, int w, int h) {
    ImageProcessing::binarize_window(src, dest, w, h,
                                     m_thresholdLeft.getCurrentValue(),
                                     m_thresholdRight.getCurrentValue(),
                                     true
                                     );
}

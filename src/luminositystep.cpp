#include "luminositystep.h"
#include "Image_Processing.h"

LuminosityStep::LuminosityStep(QObject *parent): ImageProcessingStep{parent} {
    m_name = "Luminosity";

    m_brightness.setName("Brightness");
    m_brightness.setCurrentValue(0);
    m_brightness.setMinValue(-255);
    m_brightness.setMaxValue(255);
    m_values.append(&m_brightness);
}

void LuminosityStep::applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) {
    ImageProcessing::changeLuminosityImage(src, dest, w, h, m_brightness.getCurrentValue());
}

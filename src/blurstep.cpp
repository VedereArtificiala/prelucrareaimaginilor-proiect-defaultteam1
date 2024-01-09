#include "blurstep.h"
#include "Image_Processing.h"

BlurStep::BlurStep(QObject *parent): ImageProcessingStep{parent} {
    m_name = "Blur";

    m_kernelSize.setName("Kernel Size");
    m_kernelSize.setCurrentValue(3);
    m_kernelSize.setMinValue(1);
    m_kernelSize.setMaxValue(5);
    m_values.append(&m_kernelSize);
}

void BlurStep::applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) {
    ImageProcessing::blur(src, dest, w, h, m_kernelSize.getCurrentValue());
}

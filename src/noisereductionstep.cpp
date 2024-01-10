#include "noisereductionstep.h"
#include "Image_Processing.h"

NoiseReductionStep::NoiseReductionStep(QObject *parent): ImageProcessingStep{parent} {
    m_name = "Noise Reduction";

    m_mode.setName("Mode: Aritm/Gauss");
    m_mode.setMinValue(0);
    m_mode.setMaxValue(1);
    m_mode.setCurrentValue(0);
    m_values.append(&m_mode);

    m_filterSizeX.setName("Filter Size X");
    m_filterSizeX.setMinValue(1);
    m_filterSizeX.setMaxValue(5);
    m_filterSizeX.setCurrentValue(3);
    m_values.append(&m_filterSizeX);

    m_filterSizeY.setName("Filter Size Y");
    m_filterSizeY.setMinValue(1);
    m_filterSizeY.setMaxValue(5);
    m_filterSizeY.setCurrentValue(3);
    m_values.append(&m_filterSizeY);

    m_iterations.setName("Iterations");
    m_iterations.setMinValue(0);
    m_iterations.setMaxValue(500);
    m_iterations.setCurrentValue(1);
    m_values.append(&m_iterations);
}

void NoiseReductionStep::applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) {
    ImageProcessing::NoiseReduction(src, dest, w, h,
                                    m_mode.getCurrentValue() ? MODE_GAUSS : MODE_ARITMETIC,
                                    m_filterSizeX.getCurrentValue(),
                                    m_filterSizeY.getCurrentValue(),
                                    m_iterations.getCurrentValue()
                                    );
}

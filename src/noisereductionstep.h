#ifndef NOISEREDUCTIONSTEP_H
#define NOISEREDUCTIONSTEP_H

#include "imageprocessingstep.h"

class NoiseReductionStep : public ImageProcessingStep {
public:
    explicit NoiseReductionStep(QObject *parent = nullptr);

    // ImageProcessingStep interface
    void applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) override;
private:
    ImageProcessingStepValue m_mode = ImageProcessingStepValue();
    ImageProcessingStepValue m_filterSizeX = ImageProcessingStepValue();
    ImageProcessingStepValue m_filterSizeY = ImageProcessingStepValue();
    ImageProcessingStepValue m_iterations = ImageProcessingStepValue();
};

#endif // NOISEREDUCTIONSTEP_H

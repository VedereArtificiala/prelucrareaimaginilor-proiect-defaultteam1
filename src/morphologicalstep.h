#ifndef MORPHOLOGICALSTEP_H
#define MORPHOLOGICALSTEP_H

#include "imageprocessingstep.h"

class MorphologicalStep : public ImageProcessingStep {
public:
    explicit MorphologicalStep(QObject *parent = nullptr);

    // ImageProcessingStep interface
    void applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) override;

private:
    ImageProcessingStepValue m_erodeIterations = ImageProcessingStepValue();
    ImageProcessingStepValue m_dilateIterations = ImageProcessingStepValue();
};

#endif // MORPHOLOGICALSTEP_H

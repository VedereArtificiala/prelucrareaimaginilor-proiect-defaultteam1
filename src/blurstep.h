#ifndef BLURSTEP_H
#define BLURSTEP_H

#include "imageprocessingstep.h"

class BlurStep : public ImageProcessingStep {
public:
    explicit BlurStep(QObject *parent = nullptr);

    // ImageProcessingStep interface
public:
    void applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) override;

private:
    ImageProcessingStepValue m_kernelSize = ImageProcessingStepValue();
};

#endif // BLURSTEP_H

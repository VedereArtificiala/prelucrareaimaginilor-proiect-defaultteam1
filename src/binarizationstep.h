#ifndef BINARIZATIONSTEP_H
#define BINARIZATIONSTEP_H

#include "imageprocessingstep.h"

class BinarizationStep : public ImageProcessingStep {
public:
    explicit BinarizationStep(QObject *parent = nullptr);

    // ImageProcessingStep interface
public:
    void applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) override;

private:
    ImageProcessingStepValue threshold = ImageProcessingStepValue();
};

#endif // BINARIZATIONSTEP_H

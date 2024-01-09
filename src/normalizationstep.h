#ifndef NORMALIZATIONSTEP_H
#define NORMALIZATIONSTEP_H

#include "imageprocessingstep.h"

class NormalizationStep : public ImageProcessingStep {
public:
    explicit NormalizationStep(QObject *parent = nullptr);

    // ImageProcessingStep interface
    void applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) override;
};

#endif // NORMALIZATIONSTEP_H

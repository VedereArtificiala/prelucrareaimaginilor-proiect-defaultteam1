#ifndef LUMINOSITYSTEP_H
#define LUMINOSITYSTEP_H

#include "imageprocessingstep.h"

class LuminosityStep : public ImageProcessingStep {
public:
    explicit LuminosityStep(QObject *parent = nullptr);

private:
    ImageProcessingStepValue m_brightness = ImageProcessingStepValue();

    // ImageProcessingStep interface
public:
    void applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) override;
};

#endif // LUMINOSITYSTEP_H

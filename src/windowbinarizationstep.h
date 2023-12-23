#ifndef WINDOWBINARIZATIONSTEP_H
#define WINDOWBINARIZATIONSTEP_H

#include <QImage>
#include "imageprocessingstep.h"

class WindowBinarizationStep : public ImageProcessingStep {
public:
    explicit WindowBinarizationStep(QObject *parent = nullptr);

    void applyProcessing(unsigned char* src, unsigned char*& dest, int w, int h) override;

private:
    ImageProcessingStepValue m_thresholdLeft = ImageProcessingStepValue();
    ImageProcessingStepValue m_thresholdRight = ImageProcessingStepValue();
};

#endif // WINDOWBINARIZATIONSTEP_H

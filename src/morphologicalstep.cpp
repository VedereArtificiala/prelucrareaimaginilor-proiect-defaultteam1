#include "morphologicalstep.h"
#include "Image_Processing.h"

MorphologicalStep::MorphologicalStep(QObject *parent): ImageProcessingStep{parent} {
    m_name = "Morphological operations";

    m_erodeIterations.setName("Erode Iterations");
    m_erodeIterations.setMinValue(0);
    m_erodeIterations.setMaxValue(10);
    m_erodeIterations.setCurrentValue(0);
    m_values.append(&m_erodeIterations);

    m_dilateIterations.setName("Dilate Iterations");
    m_dilateIterations.setMinValue(0);
    m_dilateIterations.setMaxValue(10);
    m_dilateIterations.setCurrentValue(0);
    m_values.append(&m_dilateIterations);
}

void MorphologicalStep::applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) {
    ImageProcessing::DeleteSmallArtifacts(src, dest, w, h,
                                          m_erodeIterations.getCurrentValue(),
                                          m_dilateIterations.getCurrentValue()
                                          );
}

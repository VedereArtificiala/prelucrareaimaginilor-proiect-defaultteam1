#include "normalizationstep.h"
#include "Image_Processing.h"

NormalizationStep::NormalizationStep(QObject *parent): ImageProcessingStep{parent} {
    m_name = "Normalization";
}

void NormalizationStep::applyProcessing(unsigned char *src, unsigned char *&dest, int w, int h) {
    ImageProcessing::normalizeImage(src, dest, w, h);
}

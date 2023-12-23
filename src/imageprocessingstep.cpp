#include "imageprocessingstep.h"

ImageProcessingStep::ImageProcessingStep(QObject *parent): QObject{parent} {
}

const QList<ImageProcessingStepValue *> &ImageProcessingStep::getValues() const {
    return m_values;
}

void ImageProcessingStep::setValues(const QList<ImageProcessingStepValue *> &newValues) {
    if (m_values == newValues)
        return;
    m_values = newValues;
    emit valuesChanged();
}

const QString &ImageProcessingStep::getName() const {
    return m_name;
}

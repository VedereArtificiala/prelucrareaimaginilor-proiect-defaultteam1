#include "imageprocessingstepvalue.h"
#include <QtDebug>

ImageProcessingStepValue::ImageProcessingStepValue(QObject *parent): QObject{parent} {
}

int ImageProcessingStepValue::getMinValue() const {
    return minValue;
}

void ImageProcessingStepValue::setMinValue(int newMinValue) {
    if (minValue == newMinValue)
        return;

    minValue = newMinValue;
    emit minValueChanged();
}

int ImageProcessingStepValue::getCurrentValue() const {
    return currentValue;
}

void ImageProcessingStepValue::setCurrentValue(int newCurrentValue) {
    if (currentValue == newCurrentValue)
        return;

    currentValue = newCurrentValue;
    emit currentValueChanged();
}

int ImageProcessingStepValue::getMaxValue() const {
    return maxValue;
}

void ImageProcessingStepValue::setMaxValue(int newMaxValue) {
    if (maxValue == newMaxValue)
        return;

    maxValue = newMaxValue;
    emit maxValueChanged();
}

const QString &ImageProcessingStepValue::getName() const {
    return name;
}

void ImageProcessingStepValue::setName(const QString &newName) {
    if (name == newName)
        return;

    name = newName;
    emit nameChanged();
}

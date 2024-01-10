#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>

#include "imageprovider.h"
#include "imageprocessinglist.h"
#include "diagnosisresult.h"

class ImageProcessor : public QObject {
    Q_OBJECT

    Q_PROPERTY(ImageProcessingList* steps
               MEMBER m_steps
               READ steps
               WRITE setSteps
               NOTIFY stepsChanged)

    Q_PROPERTY(ImageProvider* provider
               MEMBER m_provider
               READ provider
               NOTIFY providerChanged)

    Q_PROPERTY(bool askedForDiagnosis
               MEMBER m_askedForDiagnosis
               READ askedForDiagnosis
               WRITE setAskedForDiagnosis
               NOTIFY askedForDiagnosisChanged)

    Q_PROPERTY(DiagnosisResult diagnosisResult
               MEMBER m_diagnosisResult
               READ diagnosisResult
               WRITE setDiagnosisResult
               NOTIFY diagnosisResultChanged)

public:
    explicit ImageProcessor(QObject *parent = nullptr);
    ~ImageProcessor();

    ImageProvider *provider();

    Q_INVOKABLE void processImage();
    void calculateDiagnosis(unsigned char* src, int w, int h);

    ImageProcessingList *steps() const;
    void setSteps(ImageProcessingList *newSteps);

    bool askedForDiagnosis() const;
    void setAskedForDiagnosis(bool newAskedForDiagnosis);

    const DiagnosisResult &diagnosisResult() const;
    void setDiagnosisResult(const DiagnosisResult &newDiagnosis);

signals:
    void providerChanged();

    void stepsChanged();

    void askedForDiagnosisChanged();

    void diagnosisResultChanged();

private:
    ImageProvider *m_provider = nullptr;
    ImageProcessingList *m_steps = nullptr;

    bool m_askedForDiagnosis = false;
    DiagnosisResult m_diagnosisResult = {0.0, QImage()};
};

#endif // IMAGEPROCESSOR_H

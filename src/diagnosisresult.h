#ifndef DIAGNOSISRESULT_H
#define DIAGNOSISRESULT_H

#include <QObject>
#include <QImage>

struct DiagnosisResult {
    Q_GADGET
    Q_PROPERTY(double result MEMBER result)
    Q_PROPERTY(QImage finalImage MEMBER finalImage)
public:
    double result;
    QImage finalImage;
};

Q_DECLARE_METATYPE(DiagnosisResult)

#endif // DIAGNOSISRESULT_H

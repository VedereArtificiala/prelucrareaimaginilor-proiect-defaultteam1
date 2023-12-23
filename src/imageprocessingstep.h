#ifndef IMAGEPROCESSINGSTEP_H
#define IMAGEPROCESSINGSTEP_H

#include <QObject>
#include <QList>

#include "imageprocessingstepvalue.h"

class ImageProcessingStep : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString name
               MEMBER m_name
               READ getName
               NOTIFY nameChanged)

    Q_PROPERTY(QList<ImageProcessingStepValue *> values
               MEMBER m_values
               READ getValues
               NOTIFY valuesChanged)
public:
    explicit ImageProcessingStep(QObject *parent = nullptr);

    const QList<ImageProcessingStepValue *> &getValues() const;
    void setValues(const QList<ImageProcessingStepValue *> &newValues);

    virtual void applyProcessing(unsigned char *src, unsigned char*& dest, int w, int h) = 0;

    const QString &getName() const;

signals:
    void valuesChanged();
    void nameChanged();

protected:
    QString m_name;
    QList<ImageProcessingStepValue*> m_values;
};

#endif // IMAGEPROCESSINGSTEP_H

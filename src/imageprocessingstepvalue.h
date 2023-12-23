#ifndef IMAGEPROCESSINGSTEPVALUE_H
#define IMAGEPROCESSINGSTEPVALUE_H

#include <QObject>
#include <QString>

class ImageProcessingStepValue : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString name
               READ getName
               WRITE setName
               NOTIFY nameChanged)

    Q_PROPERTY(int minValue
               READ getMinValue
               WRITE setMinValue
               NOTIFY minValueChanged)

    Q_PROPERTY(int currentValue
               READ getCurrentValue
               WRITE setCurrentValue
               NOTIFY currentValueChanged)

    Q_PROPERTY(int maxValue
               READ getMaxValue
               WRITE setMaxValue
               NOTIFY maxValueChanged)

public:
    explicit ImageProcessingStepValue(QObject *parent = nullptr);

    int getMinValue() const;
    void setMinValue(int newMinValue);

    int getCurrentValue() const;
    void setCurrentValue(int newCurrentValue);

    int getMaxValue() const;
    void setMaxValue(int newMaxValue);

    const QString &getName() const;
    void setName(const QString &newName);

signals:
    void minValueChanged();
    void currentValueChanged();
    void maxValueChanged();

    void nameChanged();

private:
    QString name;

    int minValue;
    int currentValue;
    int maxValue;
};

#endif // IMAGEPROCESSINGSTEPVALUE_H

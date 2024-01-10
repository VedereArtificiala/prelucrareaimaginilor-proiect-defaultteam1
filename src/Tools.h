#pragma once
#include <QString>
#include <QImage>
#include <QDebug>

class Tools
{
	static QVector<QRgb> grayLUT;

public:
    static unsigned char* readImageGray8(const QImage &img)
    {
        QImage gray = img.convertToFormat(QImage::Format_Grayscale8);
        int w = gray.width();
        int h = gray.height();
		unsigned char *pixelValues = new unsigned char[w*h];
		for (int i = 0; i < h; i++)
            memcpy(pixelValues + i*w, gray.scanLine(i), w);
		return pixelValues;
	}

    static QImage imageGray8FromArray(unsigned char* bytes, int w, int h)
	{
        QImage img = QImage(bytes, w, h, QImage::Format_Grayscale8).copy();
//        img.setColorTable(grayLUT);
		return img;
	}

	static unsigned char* imDiff(unsigned char* im1, unsigned char* im2, int w, int h)
	{
		int size = w*h;
		unsigned char* diff = new unsigned char[size];
		for (int i = 0; i < size; i++)
			diff[i] = abs(im1[i] - im2[i]);
		return diff;
	}
};




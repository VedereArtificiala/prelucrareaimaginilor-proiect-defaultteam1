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
        int w = img.width();
        int h = img.height();
		unsigned char *pixelValues = new unsigned char[w*h];
		for (int i = 0; i < h; i++)
            memcpy(pixelValues + i*w, img.scanLine(i), w);
		return pixelValues;
	}

    static QImage imageGray8FromArray(unsigned char* bytes, int w, int h)
	{
        QImage img = QImage(bytes, w, h, w, QImage::Format_Indexed8);
        img.setColorTable(grayLUT);
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




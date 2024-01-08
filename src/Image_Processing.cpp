#include "Image_Processing.h"
#include <fstream>
using namespace ImageProcessing;

BYTE*   ImageProcessing::blur(BYTE *src, BYTE *&dest, int w, int h, int kernel_size)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	cv::blur(matSRC, matDEST, cv::Size(kernel_size, kernel_size));
    // OpenCV...

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

BYTE*   ImageProcessing::binarize(BYTE* src, BYTE*& dest, int w, int h, int threshold)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	cv::threshold(matSRC, matDEST, threshold, 255, cv::THRESH_BINARY);
    // OpenCV...

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

BYTE*   ImageProcessing::binarize_window(BYTE* src, BYTE*& dest, int w, int h, int threshold_LEFT, int threshold_RIGHT, bool inverse)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
    cv::inRange(matSRC, threshold_LEFT, threshold_RIGHT, matDEST);
	if(inverse)
		cv::bitwise_not(matDEST, matDEST);
    // OpenCV...

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

BYTE*   ImageProcessing::changeLuminosityImage(BYTE* src, BYTE*& dest, int w, int h, int Brightness)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	matDEST = matSRC + Brightness;
    // OpenCV...

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

//get histogram
BYTE*   ImageProcessing::getHistogram(BYTE* src, BYTE*& dest, int w, int h)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true, accumulate = false;

	cv::calcHist(&matSRC, 1, 0, cv::Mat(), matDEST, 1, &histSize, &histRange, uniform, accumulate);
    // OpenCV...

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

//normalize image
BYTE*   ImageProcessing::normalizeImage(BYTE* src, BYTE*& dest, int w, int h)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	cv::equalizeHist(matSRC, matDEST);
    // OpenCV...

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

//Noise reduction
BYTE*   ImageProcessing::NoiseReduction(BYTE* src, BYTE*& dest, int w, int h, unsigned int Mode, unsigned short Filter_Size_X, unsigned short Filter_Size_Y, unsigned int iterations)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	cv::Mat temp;

	if (Mode == MODE_ARITMETIC)
	{
		cv::blur(matSRC, temp, cv::Size(Filter_Size_X, Filter_Size_Y));
		for (size_t i = 0; i < iterations; i++)
		{
			cv::blur(temp, matDEST, cv::Size(Filter_Size_X, Filter_Size_Y));
			temp = matDEST;
		}
	}
	else if (Mode == MODE_GAUSS)
	{
		cv::GaussianBlur(matSRC, temp, cv::Size(Filter_Size_X, Filter_Size_Y), 0, 0);
		for (size_t i = 0; i < iterations; i++)
		{
			cv::GaussianBlur(temp, matDEST, cv::Size(Filter_Size_X, Filter_Size_Y), 0, 0);
			temp = matDEST;
		}
	}
	matDEST = temp;
    // ...OpenCV

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

//Delete Small Artficats
BYTE*   ImageProcessing::DeleteSmallArtifacts(BYTE* src, BYTE*& dest, int w, int h, unsigned int Iterations)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	cv::Mat temp;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::erode(matSRC, temp, element, cv::Point(-1, -1), Iterations);
	cv::Mat diamondKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
	cv::dilate(temp, matDEST, diamondKernel, cv::Point(-1, -1), Iterations);
    // ...OpenCV

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

BYTE*   ImageProcessing::DeleteSmallArtifacts(BYTE* src, BYTE*& dest, int w, int h, unsigned int IterationsErode, unsigned int IterationDilate)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	cv::Mat temp;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

	if(IterationsErode > 0)
		cv::erode(matSRC, temp, element, cv::Point(-1, -1), IterationsErode);
	else
		temp = matSRC;

	cv::Mat crossKernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(5, 5));
	cv::Mat diamondKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));

	if(IterationDilate > 0)
		cv::dilate(temp, matDEST, crossKernel, cv::Point(-1, -1), IterationDilate);
	else
		matDEST = temp;
    // ...OpenCV

    if ( dest )
        delete[] dest;
    dest = new unsigned char[w*h];
    memcpy(dest, matDEST.data, w*h);

    return dest;
}

void    ImageProcessing::processBinaryImage(BYTE* binary_src, BYTE*& dest, int w, int h, double min_contour_area)
{
    //TODO: Functia asta ar trebui mutata in codul de interfata grafica impreuna cu calculul diagnozei
    //      Also, cand va fi mutata, o vom schimba sa foloseasca imagini color QImage

    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, binary_src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	// Find contours
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(matSRC, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	// Filter contours by area
	std::vector<std::vector<cv::Point>> filtered_contours;
	for (const auto& contour : contours) {
		if (cv::contourArea(contour) > min_contour_area) {
			filtered_contours.push_back(contour);
		}
	}

	// Further filter by circularity or aspect ratio if needed (TODO LATER)

	// Draw contours on the destination image
	cv::cvtColor(matSRC, matDEST, cv::COLOR_GRAY2BGR);  // Convert to BGR for drawing contours
	cv::drawContours(matDEST, filtered_contours, -1, cv::Scalar(0, 255, 0), 2);
}

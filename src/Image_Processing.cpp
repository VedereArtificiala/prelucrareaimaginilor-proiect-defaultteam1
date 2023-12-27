#include "Image_Processing.h"
#include <fstream>
using namespace std;
using namespace ImageProcessing;

	#pragma region FUNCTIONS WITHOUT OPENCV!
//
//
//
///*========================================================================================================================
// * This function recieves an array of values from an image, the width and the height of the image and a threshold
// * to compare the values to. If the value is greater than the threshold, the value is set to 255, otherwise it is set to 0.
// ========================================================================================================================*/
//BYTE* ImageProcessing::binarize(const BYTE* img, int w, int h, BYTE*& img_dest, int threshold = GRAY)
//{
//	if(img_dest == NULL)
//		img_dest = new BYTE[w * h]; //If there is no image destination, create one.
//
//	for (int y = 0; y < h; y++)
//		for (int x = 0; x < w; x++)
//			img_dest[y * w + x] = img[y * w + x] > threshold ? 255 : 0;
//	return img_dest;
//}	
//
///*========================================================================================================================
// * This function recieves an array of values from an image, the width and the height of the image and returns
// * an array of bytes containing the updated values of the pixels to blur the image.
// ========================================================================================================================*/
//BYTE* ImageProcessing::blur(const BYTE* img, int w, int h, BYTE* img_dest) //TODO: Add a parameter to specify the blur intensity and range
//{
//	if(img_dest == NULL)
//		img_dest = new BYTE[w * h]; //If there is no image destination, create one.
//
//	for (int y = 0; y < h; y++)
//		for (int x = 0; x < w; x++)
//		{
//			int sum = 0;
//			for (int i = -1; i <= 1; i++)
//				for (int j = -1; j <= 1; j++)
//				{
//					int x1 = x + i;
//					int y1 = y + j;
//					if (x1 < 0)
//						x1 = 0;
//					if (x1 >= w)
//						x1 = w - 1;
//					if (y1 < 0)
//						y1 = 0;
//					if (y1 >= h)
//						y1 = h - 1;
//					sum += (int)img[y1 * w + x1];
//				}
//			img_dest[y * w + x] = sum / 9;
//		}
//	return img_dest;
//}
//
///*========================================================================================================================
//* This function recieves an array of pixels from an image, the width, an image dest and the height of the image and a value representing
//* the brightness of the image.
//* RETURNS: An array of updated values of the pixels
//========================================================================================================================*/
//BYTE* ImageProcessing::changeLuminosityImage(const BYTE* img, int w, int h, BYTE*& img_dest, int Brightness)
//{
//	if(img_dest == NULL)
//		img_dest = new BYTE[w * h]; //If there is no image destination, create one.
//	
//	int temp_value = 0;
//
//
//	Brightness = (Brightness > WHITE) ? WHITE : Brightness;
//
//	for (int y = 0; y < h; y++)
//		for (int x = 0; x < w; x++)
//		{
//			temp_value = (int)(img[y * w + x]) + (Brightness);
//			if (temp_value > WHITE)
//			{
//				temp_value = WHITE;
//			}
//            else if (temp_value < BLACK)
//			{
//                temp_value = BLACK;
//			}
//
//			img_dest[y * w + x] = (uint8_t)temp_value;
//		}
//
//	return img_dest;
//}
//
///*========================================================================================================================
//* This function recieves an array of pixels from an image, the width and the height of the image and an interval of
//* values of interest and an amplifier interval.
//* RETURNS: An array of updated values of the pixels.
//========================================================================================================================*/
//BYTE* ImageProcessing::changeContrastImage(const BYTE* img, int w, int h, BYTE* img_dest,
//										int threshold_left, int threshold_right,
//										float amp_left, float amp_right )
//{
//	if (img_dest == NULL)
//		img_dest = new BYTE[w * h]; //If there is no image destination, create one.
//
//	/* fix thresholds */
//	if (threshold_left < 0)
//	{
//		threshold_left = 0;
//	}
//	else if (threshold_left > 0xff)
//	{
//		threshold_left = 0xff;
//	}
//
//	if (threshold_right < 0)
//	{
//		threshold_right = 0;
//	}
//	else if (threshold_right >= 0xff)
//	{
//		threshold_right = 0xfe;
//	}
//
//	if (threshold_left > threshold_right)
//	{
//		int temp = threshold_left;
//		threshold_left = threshold_right;
//		threshold_right = temp;
//	}
//	/* end of fixing thresholds */
//
//	if (amp_left < threshold_left)
//	{
//		amp_left = float(threshold_left);
//	}
//	if (amp_right > threshold_right)
//	{
//		amp_right = float(threshold_right);
//	}
//
//	if (amp_left > amp_right)
//	{
//		int temp = amp_left;
//		amp_left = amp_right;
//		amp_right = temp;
//	}
//
//	const float m = amp_left / threshold_left;
//	const float n = (float)(amp_right - amp_left) / (threshold_right - threshold_left);
//	const float p = (float)(0xff - threshold_right);
//	int temp;
//	for (int y = 0; y < h; y++)
//		for (int x = 0; x < w; x++)
//		{
//
//			if (img[y * w + x] <= threshold_left)
//			{
//				temp = (float)(img[y * w + x]) * m;
//				img_dest[y * w + x] = (temp > 0xff) ? 0xff : (temp < 0) ? 0 : temp;
//			}
//			else if (img[y * w + x] > threshold_left && img[y * w + x] <= threshold_right)
//			{
//				temp = (float)n + amp_left;
//				img_dest[y * w + x] = (temp > 0xff) ? 0xff : (temp < 0) ? 0 : temp;
//			}
//			else if (img[y * w + x] > threshold_right)
//			{
//				temp = (float)n + amp_right;
//				img_dest[y * w + x] = (temp > 0xff) ? 0xff : (temp < 0) ? 0 : temp;
//			}
//		}
//
//	return img_dest;
//}
//
///*========================================================================================================================
//* This function recieves an array of pixels from an image, the width and the height of the image, an image destination,
//* a threshold interval and a boolean that specifies if the values outside the interval should be set to 0 or to the original value. 
//* RETURNS: An array of updated values of the pixels if there is no image destination, otherwise it returns null and updates the image destination.
//* ========================================================================================================================*/
//BYTE* ImageProcessing::binarize_window(const BYTE* img_source, int w, int h, BYTE* img_dest, BYTE threshold_LEFT, BYTE threshold_RIGHT, bool MakeIntervalBlack)
//{
//	if(img_dest == NULL)
//		img_dest = new BYTE[w * h]; //If there is no image destination, create one.
//	
//	if (threshold_LEFT > threshold_RIGHT)
//	{
//		BYTE temp = threshold_LEFT;
//		threshold_LEFT = threshold_RIGHT;
//		threshold_RIGHT = temp;
//	}
//
//	for (int y = 0; y < h; y++)
//		for (int x = 0; x < w; x++)
//		{
//			if(img_source[y*w+x] >= threshold_LEFT && img_source[y*w+x] <= threshold_RIGHT)
//				img_dest[y * w + x] = WHITE;
//			else
//				img_dest[y * w + x] = MakeIntervalBlack?BLACK: img_source[y*w+x];
//		} 
//	return img_dest;
//}
//
///*========================================================================================================================
//* This function recieves two arrays, one containing the values of the pixels from an source image and one containing
//* the values of the pixels from a destination image, the width and the height of the images.
//* The function will create a new image inside destination image by adjusting the values of the histogram of the source.
//* ========================================================================================================================*/
//
//BYTE* ImageProcessing::getHistogram(const BYTE* img, int w, int h) {
//	BYTE* histogram = new BYTE[256];				//Values from 0 to 255, so there is no need to allocate more memory.
//    //memset(histogram, 0, 256 * sizeof(BYTE));
//
//	for (size_t i = 0; i < w * h; i++) {	
//		histogram[img[i]]++;						//Increment the value of the histogram at the index of the value of the pixel.
//	}
//
//	return histogram;								//Return the histogram.
//}
//
//
//double* ImageProcessing::normalizeHistogram(BYTE* histogram, int size) { // size = height * width
//	double* r = new double[256];
//    //memset(r, 0, 256 * sizeof(double));
//
//	for (int i = 0; i < 256; i++) {
//		r[i] = (double)histogram[i] / size;
//	}
//
//	return r;
//}
//
//BYTE* ImageProcessing::normalizeImage(BYTE* img, int w, int h, double* normHisto) {
//	BYTE* result = new BYTE[w * h];
//
//	for (int y = 0; y < h; y++)
//		for (int x = 0; x < w; x++) {
//			double sum = 0;
//			for (int i = 0; i < img[y * w + x]; i++) {
//				sum += normHisto[i];
//			}
//			int value = (int)(255 * sum);
//			BOUND(value, 0, 255);
//			result[y * w + x] = value;
//		}
//
//	return result;
//}
//
//BYTE* ImageProcessing::adaptiveNormalize(BYTE* img, int w, int h, int n) {
//	BYTE* result = new BYTE[w * h];
//
//	for (int y = 0; y < h; y++) {
//		for (int x = 0; x < w; x++) {
//			// TODO: Boundary checking for the small section!
//			BYTE* smallSection = (BYTE*)(img + (y - n / 2) * w + x - n / 2);
//
//			BYTE* smallHistogram = getHistogram(smallSection, n, n);
//			double* normalizedSmallHistogram = normalizeHistogram(smallHistogram, n * n);
//
//			double sum = 0;
//			for (int i = 0; i < img[y * w + x]; i++) {
//				sum += normalizedSmallHistogram[i];
//			}
//			int value = (int)(255 * sum);
//			BOUND(value, 0, 255);
//			result[y * w + x] = value;
//		}
//	}
//
//	return result;
//}
///*========================================================================================================================
//* This function recieves an array of pixels from an image, the width and the height of the image and a destination image
//* and returns an array of updated values of the pixels with less noise based on the gaussian filter or median filter.
//* ========================================================================================================================*/
//BYTE* ImageProcessing::NoiseReduction(const BYTE* img, int w, int h, BYTE* img_dest, unsigned int Mode, unsigned short Filter_Size_X, unsigned short Filter_Size_Y)
//{
//	if(img_dest == NULL)
//		img_dest = new BYTE[w * h]; //If there is no image destination, create one.
//
//	double* filter_main= 0;
//	if (Mode == MODE_ARITMETIC)												//if Artimetic mode was selected
//	{
//		filter_main = (double*)malloc(Filter_Size_X * Filter_Size_Y);		//allocate memory for the filter
//		if (!filter_main)													//if the memory allocation failed
//			return 0;														//return 0.
//
//		for (size_t i = 0; i < Filter_Size_X * Filter_Size_Y; i++)			//for each element of the filter
//		{
//			filter_main[i] = 1;												//set the value to 1
//		}
//	}
//	else if (Mode == MODE_GAUSS)											//if Gauss mode was selected	
//	{
//		double filter[5 * 5] = { 1 ,4 ,7 ,4 ,1 ,							//Set the filter to the values of the Gauss filter ( values found on internet :P)
//								4,16,26,16,4,
//								7,26,41,26,7,
//								4,16 ,26 ,16 ,4 ,
//								1,4 ,7,4,1
//		};
//		Filter_Size_X = 5;
//		Filter_Size_Y = 5;
//		filter_main = filter;
//	}
//
//
//	double sum1 = (Mode == MODE_ARITMETIC) ? Filter_Size_X * Filter_Size_Y : SUM_OF_THE_GAUSSIAN_FILTER; //if the mode is arithmetic, the sum is the number of elements in the filter, otherwise it is the sum of the values of the Gauss filter
//
//	for (int y = 1; y < h - 1; y++)
//	{
//		for (int x = 1; x < w - 1; x++)
//		{
//			double sum = 0;
//			for (size_t fy = 0; fy < Filter_Size_Y; ++fy)
//			{
//				for (size_t fx = 0; fx < Filter_Size_X; ++fx)
//				{
//					sum += img[(y - 1 + fy) * w + (x - 1 + fx)] * filter_main[fy * Filter_Size_X + fx];
//				}
//			}
//			img_dest[y * w + x] = sum / sum1;
//		}
//	}
//
//	return img_dest;
//}
//
///*========================================================================================================================
//* This function recieves an array of pixels from an image, the width and the height of the image and a destination image
//* and it lets you apply a filter to the image defined by the developer.
//* ========================================================================================================================*/
//BYTE* ImageProcessing::ApplyFilter(const BYTE* img, int iw, int ih, double* filtru, int fs, BYTE* img_dest) {
//	if(img_dest == NULL)
//		img_dest = new BYTE[iw * ih]; //If there is no image destination, create one.)
//	
//
//	for (int y = 0; y < ih; y++) {
//		for (int x = 0; x < iw; x++) {
//			double sum = 0;
//
//			for (int i = -fs / 2; i <= fs / 2; i++) {
//				for (int j = -fs / 2; j <= fs / 2; j++) {
//					if (((y + i) * iw + x + j) >= 0 && ((y + i) * iw + x + j) < iw * ih)
//						sum += img[(y + i) * iw + x + j] * filtru[(i + fs / 2) * fs + j + fs / 2];
//				}
//			}
//
//			if (sum > 255) {
//				img_dest[y * iw + x] = 255;
//			}
//			else if (sum < 0) {
//				img_dest[y * iw + x] = 0;
//			}
//			else {
//				img_dest[y * iw + x] = sum;
//			}
//
//		}
//	}
//
//	return img_dest;
//}
//
//double ImageProcessing::get_filter_sum(double* filter, size_t x, size_t y)
//{
//	if (filter == (void*)0)
//	{
//		return 1;
//	}
//	double sum = 0;
//	for (size_t fy = 0; fy < y; fy = fy + 1)
//	{
//		for (size_t fx = 0; fx < x; fx++)
//		{
//			sum += filter[fy * y + fx];
//		}
//	}
//	return sum;
//}
///*========================================================================================================================
//* This function recieves an array of pixels from an image, the width and the height of the image and a destination image:
//* Returns an array of updated values of the pixels , with the image being outlined using the Sobel filter.
//* Values are updated in the destination image too.
//=========================================================================================================================*/
//BYTE* ImageProcessing::sobelOutline(const BYTE* img, int w, int h, BYTE*& img_dest) {
//	double filtruX[] = {
//		-1, 0, 1,
//		-2, 0, 2,
//		-1, 0, 1
//	};
//	if (img_dest)	//If there is a destination image
//		delete[] img_dest;
//	img_dest = ApplyFilter(img, w, h, filtruX, 3,NULL);
//
//	double filtruY[] = {
//		-1, -2, -1,
//		0, 0, 0,
//		1, 2, 1
//	};
//
//	BYTE* rezY = ApplyFilter(img, w, h, filtruY, 3,NULL);
//
//	for (int y = 0; y < h; y++) {
//		for (int x = 0; x < w; x++) {
//			img_dest[y * w + x] += rezY[y * w + x];
//		}
//	}
//	delete[] rezY;
//
//	return img_dest;
//}
//
//BYTE* ImageProcessing::prewittOutline(const BYTE* img, int w, int h, BYTE*& img_dest) {
//	double filtruX[] = {
//		-1, 0, 1,
//		-1, 0, 1,
//		-1, 0, 1
//	};
//
//	if (img_dest)	//If there is a destination image
//		delete[] img_dest;
//	img_dest = ApplyFilter(img, w, h, filtruX, 3, NULL);
//
//	double filtruY[] = {
//		-1, -1, -1,
//		0, 0, 0,
//		1, 1, 1
//	};
//
//	BYTE* rezY = ApplyFilter(img, w, h, filtruY, 3, NULL);
//
//	for (int y = 0; y < h; y++) {
//		for (int x = 0; x < w; x++) {
//			img_dest[y * w + x] += rezY[y * w + x];
//		}
//	}
//
//	delete[] rezY;
//
//	return img_dest;
//}
#pragma endregion Do not use these functions since they are slower and probably buggy.


cv::Mat		ImageProcessing::blur(const cv::Mat& matSRC, cv::Mat& matDEST, int kernel_size )
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

	cv::blur(matSRC, matDEST, cv::Size(kernel_size, kernel_size));

	return matDEST;
}

cv::Mat		ImageProcessing::binarize(const cv::Mat& matSRC, cv::Mat& matDEST, int threshold)
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

	cv::threshold(matSRC, matDEST, threshold, 255, cv::THRESH_BINARY);

	return matDEST;

}
cv::Mat		ImageProcessing::binarize_window(const cv::Mat& matSRC, cv::Mat& matDEST, int threshold_LEFT, int threshold_RIGHT, bool inverse)
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

	cv::inRange(matSRC, threshold_LEFT, threshold_RIGHT, matDEST);
	if(inverse)
		cv::bitwise_not(matDEST, matDEST);


	return matDEST;
}

cv::Mat		ImageProcessing::changeLuminosityImage(const cv::Mat& matSRC, cv::Mat& matDEST, int Brightness)
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

	matDEST = matSRC + Brightness;

	return matDEST;
}

//get histogram
cv::Mat		ImageProcessing::getHistogram(const cv::Mat& matSRC, cv::Mat& matDEST)
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true, accumulate = false;

	cv::calcHist(&matSRC, 1, 0, cv::Mat(), matDEST, 1, &histSize, &histRange, uniform, accumulate);

	return matDEST;
}

//normalize image
cv::Mat		ImageProcessing::normalizeImage(const cv::Mat& matSRC, cv::Mat& matDEST)
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

	cv::equalizeHist(matSRC, matDEST);

	return matDEST;
}

//Noise reduction
cv::Mat		ImageProcessing::NoiseReduction(const cv::Mat& matSRC, cv::Mat& matDEST, unsigned int Mode, unsigned short Filter_Size_X, unsigned short Filter_Size_Y, unsigned int iterations)
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);
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

	return matDEST;
}

//Delete Small Artficats
cv::Mat		ImageProcessing::DeleteSmallArtifacts(const cv::Mat& matSRC, cv::Mat& matDEST, unsigned int Iterations)
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

	cv::Mat temp;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::erode(matSRC, temp, element, cv::Point(-1, -1), Iterations);
	cv::Mat diamondKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
	cv::dilate(temp, matDEST, diamondKernel, cv::Point(-1, -1), Iterations);

	return matDEST;
}

cv::Mat ImageProcessing::DeleteSmallArtifacts(const cv::Mat& matSRC, cv::Mat& matDEST, unsigned int IterationsErode, unsigned int IterationDilate)
{
	if (matDEST.empty())
		matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

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

	
	return matDEST;
}

void ImageProcessing::processBinaryImage(const cv::Mat& matSRC, cv::Mat& matDEST, double min_contour_area) 
{
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

#ifndef _IMAGE_PROCESSING_H
#define _IMAGE_PROCESSING_H



//Create multiple deviders with comments for inclusions, macros, functions, typedefs, etc
//====================================================================================================
//Header Includes
//====================================================================================================

#include "Image_Processing_Cfg.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
namespace ImageProcessing
{
//====================================================================================================
//Macros and Defines
//====================================================================================================

#define WHITE 255
#define BLACK 0
#define GRAY 128
#define SUM_OF_THE_GAUSSIAN_FILTER 273

#define BOUND(x, min, max) (x=(x < min ? min : (x > max ? max : x)))
//====================================================================================================
//Data types
//====================================================================================================
typedef unsigned char BYTE;


struct Pixel {
	BYTE red;
	BYTE green;
	BYTE blue;
};

//====================================================================================================
//Function prototypes 
//====================================================================================================

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/*															FUNCTIONS NOT USED CHECK OPENCV FUNCTIONS BELOW												       */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
	#pragma region FUNCTIONS WITHOUT OPENCV!
//
//
//BYTE*		binarize(const BYTE* img, int w, int h, BYTE*& img_dest, int threshold);
//
//BYTE*		binarize_window(const BYTE* img, int w, int h, BYTE* img_dest = NULL, BYTE threshold_LEFT = BLACK, BYTE threshold_RIGHT = WHITE, bool MakeIntervalBlack = true);
//
//BYTE*		blur(const BYTE* img, int w, int h, BYTE* img_dest = NULL);
//
//BYTE*		changeContrastImage(const BYTE* img, int w, int h, BYTE* img_dest = NULL,
//								int threshold_left=0, int threshold_right=255, 
//								float amp_left=128, float amp_right=128);
//
//BYTE*		changeLuminosityImage(const BYTE* img, int w, int h, BYTE*& img_dest, int Brightness = 128);
//
//BYTE*		NoiseReduction(const BYTE* img, int w, int h, BYTE* img_dest = NULL, unsigned int Mode = MODE_ARITMETIC, unsigned short Filter_Size_X = filterHeight_1, unsigned short Filter_Size_Y = filterHeight_1);
//
//double		get_filter_sum(double* filter, size_t x, size_t y);
//
////BYTE*		FilterImage(BYTE* img, int w, int h, double* filter,
////			unsigned short Filter_Size_X = filterHeight_1, unsigned short Filter_Size_Y = filterHeight_1);			UPDATED 
//BYTE*		ApplyFilter(const BYTE* img, int iw, int ih, double* filtru, int fs, BYTE* img_dest);
//BYTE*		adaptiveNormalize(BYTE* img, int w, int h, int n);
//BYTE*		normalizeImage(BYTE* img, int w, int h, double* normHisto);
//double*		normalizeHistogram(BYTE* histogram, int size);
//BYTE*		getHistogram(const BYTE* img, int w, int h);
//BYTE*		sobelOutline(const BYTE* img, int w, int h, BYTE*& img_dest);
//BYTE*		prewittOutline(const BYTE* img, int w, int h, BYTE*& img_dest);
#pragma endregion Do not use these functions since they are slower and probably buggy.
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

/*OpenCV Functions: They must take a matSRC and a matDEST (+ some parameters for the algorithms) as parameters and return a matDEST*/

cv::Mat		blur(const cv::Mat& matSRC, cv::Mat& matDEST, int kernel_size = 3);
cv::Mat		binarize(const cv::Mat& matSRC, cv::Mat& matDEST, int threshold);
cv::Mat		binarize_window(const cv::Mat& matSRC, cv::Mat& matDEST, int threshold_LEFT = BLACK, int threshold_RIGHT = WHITE, bool inverse = false);
cv::Mat		changeLuminosityImage(const cv::Mat& matSRC, cv::Mat& matDEST, int Brightness = 0);
cv::Mat		NoiseReduction(const cv::Mat& matSRC, cv::Mat& matDEST, unsigned int Mode = MODE_ARITMETIC, unsigned short Filter_Size_X = filterHeight_1, unsigned short Filter_Size_Y = filterHeight_1, unsigned int iterations = 1);
cv::Mat		getHistogram(const cv::Mat& matSRC, cv::Mat& matDEST);
cv::Mat		normalizeImage(const cv::Mat& matSRC, cv::Mat& matDEST);
cv::Mat		DeleteSmallArtifacts(const cv::Mat& matSRC, cv::Mat& matDEST, unsigned int Iterations);
cv::Mat		DeleteSmallArtifacts(const cv::Mat& matSRC, cv::Mat& matDEST, unsigned int IterationsErode, unsigned int IterationDilate);
void		processBinaryImage(const cv::Mat& binary_src, cv::Mat& dest, double min_contour_area = 100.0);
//cv::Mat		ImageProcessing::RegionGrowing(const cv::Mat& matSRC, cv::Mat& matDEST, int threshold, int x, int y);

//====================================================================================================
//Global variables
//====================================================================================================
}
#endif // !_IMAGE_PROCESSING_H

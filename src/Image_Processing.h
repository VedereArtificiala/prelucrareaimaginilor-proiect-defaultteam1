#ifndef _IMAGE_PROCESSING_H
#define _IMAGE_PROCESSING_H



//Create multiple deviders with comments for inclusions, macros, functions, typedefs, etc
//====================================================================================================
//Header Includes
//====================================================================================================

#include "Image_Processing_Cfg.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
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

/*OpenCV Functions: They must take a src and a dest (+ some parameters for the algorithms) as parameters and return a matDEST*/

BYTE*   blur(BYTE* src, BYTE*& dest, int w, int h, int kernel_size = 3);
BYTE*   binarize(BYTE* src, BYTE*& dest, int w, int h, int threshold);
BYTE*   binarize_window(BYTE* src, BYTE*& dest, int w, int h, int threshold_LEFT = BLACK, int threshold_RIGHT = WHITE, bool inverse = false);
BYTE*   changeLuminosityImage(BYTE* src, BYTE*& dest, int w, int h, int Brightness = 0);
BYTE*   NoiseReduction(BYTE* src, BYTE*& dest, int w, int h, unsigned int Mode = MODE_ARITMETIC, unsigned short Filter_Size_X = filterHeight_1, unsigned short Filter_Size_Y = filterHeight_1, unsigned int iterations = 1);
BYTE*   getHistogram(BYTE* src, BYTE*& dest, int w, int h);
BYTE*   normalizeImage(BYTE* src, BYTE*& dest, int w, int h);
//BYTE*   DeleteSmallArtifacts(BYTE* src, BYTE*& dest, int w, int h, unsigned int Iterations); // Better version below?
BYTE*   DeleteSmallArtifacts(BYTE* src, BYTE*& dest, int w, int h, unsigned int IterationsErode, unsigned int IterationDilate);
double		processBinaryImage(const cv::Mat& binary_src, cv::Mat& dest, double min_contour_area = 100.0, double max_contour_area=DBL_MAX);
bool		rayTraceCentroids(const cv::Mat& matSRC, const cv::Point2d& centroid, const unsigned int N_Rays, double acceptable_deviation = 1e-6);
//====================================================================================================
//Global variables
//====================================================================================================
}
#endif // !_IMAGE_PROCESSING_H

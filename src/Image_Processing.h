#ifndef _IMAGE_PROCESSING_H
#define _IMAGE_PROCESSING_H



//Create multiple deviders with comments for inclusions, macros, functions, typedefs, etc
//====================================================================================================
//Header Includes
//====================================================================================================

#include "Image_Processing_Cfg.h"
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
BYTE*		grayscale(unsigned char* img, int w, int h);
BYTE*		binarize(unsigned char* img, int w, int h, int threshold);
BYTE*		binarize_window(unsigned char* img, int w, int h, BYTE threshold_LEFT = BLACK, BYTE threshold_RIGHT = WHITE, bool MakeIntervalBlack = true);
BYTE*		blur(BYTE* img, int w, int h);
Pixel*		ReadJPGImage(const char* filename);
BYTE*		changeContrastImage(BYTE* img, int w, int h, int threshold_left, int threshold_right, float amp_left, float amp_right);
bool		WriteJPGImage(const char* filename, Pixel* pixels, int width, int height);

BYTE*		changeLuminosityImage(BYTE* img, int w, int h, int Brightness = 0);
//====================================================================================================
//Global variables
//====================================================================================================
}
#endif // !_IMAGE_PROCESSING_H
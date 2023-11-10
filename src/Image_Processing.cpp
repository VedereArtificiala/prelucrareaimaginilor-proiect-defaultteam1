#include "Image_Processing.h"
#include <fstream>
using namespace std;
using namespace ImageProcessing;

/*========================================================================================================================
 * This function recieves an array of pixels from an image, the width and the height of the image and returns
 * an array of bytes containing the grayscale values of the pixels.	
 ========================================================================================================================*/
BYTE* ImageProcessing::grayscale(BYTE* img, int w, int h) //TODO: FIX
{
	BYTE* result = new BYTE[w * h];
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			Pixel p;
			p.red = img[(y * w + x) * 3];
			p.green = img[(y * w + x) * 3 + 1];
			p.blue = img[(y * w + x) * 3 + 2];
 
			/*make sure the values are in the range[0, 255]*/
			int value = ((int)p.red + (int)p.green + (int)p.blue) / 3;
			if(value < 0)
				value = 0;
			if(value > 255)
				value = 255;

			result[y * w + x] = (BYTE)( value );
		}
	return result;
}

/*========================================================================================================================
 * This function recieves an array of values from an image, the width and the height of the image and a threshold
 * to compare the values to. If the value is greater than the threshold, the value is set to 255, otherwise it is set to 0.
 ========================================================================================================================*/
BYTE* ImageProcessing::binarize(BYTE* img, int w, int h, int threshold = GRAY)
{
	BYTE* result = new BYTE[w * h];
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
            result[y * w + x] = img[y * w + x] > threshold ? 255 : 0;
	return result;
}	

/*========================================================================================================================
 * This function recieves an array of values from an image, the width and the height of the image and returns
 * an array of bytes containing the updated values of the pixels to blur the image.
 ========================================================================================================================*/
BYTE* ImageProcessing::blur(BYTE* img, int w, int h) //TODO: Add a parameter to specify the blur intensity and range
{
	BYTE* result = new BYTE[w * h];
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			int sum = 0;
			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++)
				{
					int x1 = x + i;
					int y1 = y + j;
					if (x1 < 0)
						x1 = 0;
					if (x1 >= w)
						x1 = w - 1;
					if (y1 < 0)
						y1 = 0;
					if (y1 >= h)
						y1 = h - 1;
					sum += (int)img[y1 * w + x1];
				}
			result[y * w + x] = sum / 9;
		}
	return result;
}

/*========================================================================================================================
 * This function recieves the path to the file, an array of pixels from an image, the width and the height of the image
 * and writes the image to the file.
 * RETURNS: true if the file could not be opened, false otherwise.
 ========================================================================================================================*/
bool ImageProcessing::WriteJPGImage(const char* filename, Pixel* pixels, int width, int height) {
	// Open the file.
	ofstream file(filename, ios::binary);
	if (!file.is_open()) {
		cout << "Error opening file: " << filename << endl;
		return true;
	}

	/* Write pixels [TBD] */
	file.write((char*)pixels, width * height * sizeof(Pixel));

	// Close the file.
	file.close();
	return ERROR_NO_ERROR;
}

/*========================================================================================================================
* This function recieves the path to the file and returns an array with data and metadata from the image.
========================================================================================================================*/
Pixel* ImageProcessing::ReadJPGImage(const char* filename) {
	/* Open the file. */
	ifstream file(filename, ios::binary);
	if (!file.is_open()) {
		cout << "Error opening file: " << filename << endl;
		return ERROR_OPENING_FILE;
	}

	/* Get the file size. */
	long file_size = file.seekg(0, ios::end).tellg();
	file.seekg(0, ios::beg);

	// Allocate memory to store the image data.
	Pixel* pixels = new Pixel[file_size];

	// Read the image data into the memory.
	file.read((char*)pixels, file_size);

	// Close the file.
	file.close();

	return pixels;
}

/*========================================================================================================================
* This function recieves an array of pixels from an image, the width and the height of the image and a value representing
* the brightness of the image.
* RETURNS: An array of updated values of the pixels.
========================================================================================================================*/
BYTE* ImageProcessing::changeLuminosityImage(BYTE* img, int w, int h, int Brightness)
{
	BYTE* result = new BYTE[w * h];
	int temp_value = 0;


	Brightness = (Brightness > WHITE) ? WHITE : Brightness;

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			temp_value = (int)(img[y * w + x]) + (Brightness);
			if (temp_value > WHITE)
			{
				temp_value = WHITE;
			}
            else if (temp_value < BLACK)
			{
                temp_value = BLACK;
			}

			result[y * w + x] = (uint8_t)temp_value;
		}

	return result;
}

/*========================================================================================================================
* This function recieves an array of pixels from an image, the width and the height of the image and an interval of
* values of interest and an amplifier interval.
* RETURNS: An array of updated values of the pixels.
========================================================================================================================*/
BYTE* ImageProcessing::changeContrastImage(BYTE* img, int w, int h,
	int threshold_left = 0, int threshold_right = 0xff,
	float amp_left = 0, float amp_right = 255)
{
	BYTE* result = new BYTE[w * h];

	/* fix thresholds */
	if (threshold_left < 0)
	{
		threshold_left = 0;
	}
	else if (threshold_left > 0xff)
	{
		threshold_left = 0xff;
	}

	if (threshold_right < 0)
	{
		threshold_right = 0;
	}
	else if (threshold_right >= 0xff)
	{
		threshold_right = 0xfe;
	}

	if (threshold_left > threshold_right)
	{
		int temp = threshold_left;
		threshold_left = threshold_right;
		threshold_right = temp;
	}
	/* end of fixing thresholds */

	if (amp_left < threshold_left)
	{
		amp_left = float(threshold_left);
	}
	if (amp_right > threshold_right)
	{
		amp_right = float(threshold_right);
	}

	if (amp_left > amp_right)
	{
		int temp = amp_left;
		amp_left = amp_right;
		amp_right = temp;
	}

	const float m = amp_left / threshold_left;
	const float n = (float)(amp_right - amp_left) / (threshold_right - threshold_left);
	const float p = (float)(0xff - threshold_right);
	int temp;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{

			if (img[y * w + x] <= threshold_left)
			{
				temp = (float)(img[y * w + x]) * m;
				result[y * w + x] = (temp > 0xff) ? 0xff : (temp < 0) ? 0 : temp;
			}
			else if (img[y * w + x] > threshold_left && img[y * w + x] <= threshold_right)
			{
				temp = (float)n + amp_left;
				result[y * w + x] = (temp > 0xff) ? 0xff : (temp < 0) ? 0 : temp;
			}
			else if (img[y * w + x] > threshold_right)
			{
				temp = (float)n + amp_right;
				result[y * w + x] = (temp > 0xff) ? 0xff : (temp < 0) ? 0 : temp;
			}
		}

	return result;
}
/*========================================================================================================================
* This function recieves an array of pixels from an image, the width and the height of the image, a threshold interval
* and a boolean that specifies if the values outside the interval should be set to 0 or to the original value. 
* RETURNS: An array of updated values of the pixels.
* ========================================================================================================================*/
BYTE* ImageProcessing::binarize_window(BYTE* img, int w, int h, BYTE threshold_LEFT , BYTE threshold_RIGHT , bool MakeIntervalBlack  )
{
	BYTE* result = new BYTE[w * h];
	
	if (threshold_LEFT > threshold_RIGHT)
	{
		BYTE temp = threshold_LEFT;
		threshold_LEFT = threshold_RIGHT;
		threshold_RIGHT = temp;
	}

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			if(img[y*w+x] >= threshold_LEFT && img[y*w+x] <= threshold_RIGHT)
				result[y * w + x] = WHITE;
			else
				result[y * w + x] = MakeIntervalBlack?BLACK:img[y*w+x];
		} 
	return result;
}

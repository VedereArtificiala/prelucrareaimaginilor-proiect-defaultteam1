#include "Image_Processing.h"
#include <fstream>
using namespace ImageProcessing;

BYTE*   ImageProcessing::blur(BYTE *src, BYTE *&dest, int w, int h, int kernel_size)
{
    cv::Mat matSRC = cv::Mat(h, w, CV_8UC1, src);
    cv::Mat matDEST = cv::Mat(matSRC.rows, matSRC.cols, CV_8UC1);

    // OpenCV...
	cv::blur(matSRC, matDEST, cv::Size(kernel_size, kernel_size));
    // ...OpenCV

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
    // ...OpenCV

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
    // ...OpenCV

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
    // ...OpenCV

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
    // ...OpenCV

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
    // ...OpenCV

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
BYTE*   DeleteSmallArtifacts(BYTE* src, BYTE*& dest, int w, int h, unsigned int Iterations)
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


double ImageProcessing::processBinaryImage(const cv::Mat& matSRC, cv::Mat& matDEST, double min_contour_area, double max_contour_area)
{
	/* Find contours */
#if DEBUG_MODE == 1
	std::cout << "Number of channels: " << matSRC.channels() << std::endl;
#endif
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(matSRC, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	/* Filter contours by area */
	std::vector<std::vector<cv::Point>> filtered_contours;
	for (const auto& contour : contours) {
		if (cv::contourArea(contour) > min_contour_area) {
#if DEBUG_MODE == 1
			std::cout << "Contour area: " << cv::contourArea(contour) << std::endl;
#endif
			filtered_contours.push_back(contour);
		}
	}

	double total_area = 0.0;
	matDEST = cv::Mat::zeros(matSRC.size(), CV_8UC3);
	cv::drawContours(matDEST, filtered_contours, -1, cv::Scalar(255, 255, 255), cv::FILLED);
	cv::drawContours(matDEST, filtered_contours, -1, cv::Scalar(0, 255, 0), 2);
	for (const auto& contour : filtered_contours) {
		if (cv::contourArea(contour) < max_contour_area) {
			total_area += cv::contourArea(contour);

			// Calculate centroid
			cv::Moments mu = cv::moments(contour, false);
			cv::Point2d centroid(mu.m10 / mu.m00, mu.m01 / mu.m00);

			// For each centroid, check if the shape is a circle
			if (rayTraceCentroids(matSRC, centroid, 100))
			{
				cv::circle(matDEST, centroid, 5, cv::Scalar(0, 0, 255), -1); // Red circle for centroid
			}
			else {
				cv::circle(matDEST, centroid, 5, cv::Scalar(255, 0, 0), -1); // Blue circle for centroid
			}

			// Mark centroid on the destination image
			//cv::circle(matDEST, centroid, 5, cv::Scalar(0, 0, 255), -1); // Red circle for centroid
		}
	}

	

	return total_area;
}


/* 
The idea is to calculate the distances from the centroid to the edge of the shape along each ray, 
and then calculate the standard deviation of these distances. If the shape is a perfect circle, 
all distances will be equal and the standard deviation will be zero. If the shape is not a circle, 
the distances will vary and the standard deviation will be greater than zero.
*/
bool ImageProcessing::rayTraceCentroids(const cv::Mat& matSRC, const cv::Point2d& centroid, const unsigned int N_Rays, double acceptable_deviation)
{
	std::vector<double> distances;
	double angle_step = 2 * CV_PI / N_Rays;

	for (unsigned int i = 0; i < N_Rays; i++) {
		double current_angle = i * angle_step;
		cv::Point2d direction(cos(current_angle), sin(current_angle));

		for (size_t j = 0; ; j++) {
			cv::Point2d current_point;
			current_point.x = centroid.x + j * direction.x;
			current_point.y = centroid.y + j * direction.y;

			if (current_point.x < 0 || current_point.y < 0 || current_point.x >= matSRC.cols || current_point.y >= matSRC.rows) {
				break; // Skip this ray if the current point is out-of-bounds
			}

			if (matSRC.at<uchar>(cv::Point(current_point.y, current_point.x)) == 0) {
				distances.push_back(cv::norm(current_point - centroid));
				break;
			}
		}
	}

	double mean = std::accumulate(distances.begin(), distances.end(), 0.0) / distances.size();
	double sq_sum = std::inner_product(distances.begin(), distances.end(), distances.begin(), 0.0);
	double stdev = std::sqrt(sq_sum / distances.size() - mean * mean);

	return stdev < acceptable_deviation; // Use a small threshold to account for floating point errors
}

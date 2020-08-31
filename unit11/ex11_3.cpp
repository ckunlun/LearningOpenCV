#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

//͸�ӱ任
int main(int argc, char** argv)
{
	cv::Mat src = cv::imread(argv[1], 1);
	if (src.empty())
	{
		return -1;
	}
	double M = atof(argv[2]);
	cv::Mat dst(src.size(), src.type()), src2(src.size(), src.type());

	cv::logPolar(
		src,
		dst,
		cv::Point2f(src.cols * 0.5f, src.rows * 0.5f),
		M,
		cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS
	);
	cv::logPolar(
		dst,
		src2,
		cv::Point2f(src.cols * 0.5f, src.rows * 0.5f),
		M,
		cv::INTER_LINEAR | cv::WARP_INVERSE_MAP
	);
	cv::imshow("log-polar", dst);
	cv::imshow("inverse log-polar", src2);
	cv::waitKey();
	return 0;
}



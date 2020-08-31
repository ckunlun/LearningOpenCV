#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

//透视变换
int main(int argc, char** argv)
{
	cv::Mat src = cv::imread(argv[1], 1);
	if (src.empty())
	{
		return -1;
	}
	cv::Point2f srcQuad[] = { //原始图像的坐标
		cv::Point2f(0, 0), //dst Top left
		cv::Point2f(src.cols - 1, 0), //dst Top right
		cv::Point2f(src.cols - 1, src.rows - 1),//dst bottem right
		cv::Point2f(0, src.rows - 1) //dit bottem left
	};

	cv::Point2f dstQuad[] = { //转换后图像的坐标
		cv::Point2f(src.cols * 0.05f, src.rows * 0.33f), //dst Top left
		cv::Point2f(src.cols * 0.9f, src.rows * 0.25f), //dst Top right
		cv::Point2f(src.cols * 0.8f, src.rows * 0.9f), //dst bottem right
		cv::Point2f(src.cols * 0.2f, src.rows * 0.7f) //dit bottem left
	};

	cv::Mat warp_mat = cv::getPerspectiveTransform(srcQuad, dstQuad);//获取映射矩阵
	cv::Mat dst;
	cv::warpPerspective(src, dst, warp_mat, src.size(), cv::INTER_LINEAR,//对图像进行映射
		cv::BORDER_CONSTANT, cv::Scalar());
	for (int i = 0; i < 4; i++)
	{
		cv::circle(dst, dstQuad[i], 5, cv::Scalar(255, 0, 255), -1, cv::LINE_AA);
	}

	cv::imshow("test", dst);
	cv::waitKey();
	return 0;
}



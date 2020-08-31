#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

//仿射变换
int main(int argc, char** argv)
{
	cv::Mat src = cv::imread(argv[1], 1);
	if (src.empty())
	{
		return -1;
	}
	cv::Point2f srcTri[] = { //原始图像的坐标
		cv::Point2f(0, 0), //dst Top left
		cv::Point2f(src.cols - 1, 0), //dst Top right
		cv::Point2f(0, src.rows - 1) //dit bottem left
	};

	cv::Point2f dstTri[] = { //转换后图像的坐标
		cv::Point2f(src.cols * 0.f, src.rows * 0.33f), //dst Top left
		cv::Point2f(src.cols * 0.85f, src.rows * 0.25f), //dst Top right
		cv::Point2f(src.cols * 0.15f, src.rows * 0.7f) //dit bottem left
	};

	cv::Mat wrap_mat = cv::getAffineTransform(srcTri, dstTri); //计算映射矩阵
	cv::Mat dst;
	cv::warpAffine( //将相同映射用到图像上
		src,
		dst,
		wrap_mat,
		src.size(), //目标图像大小
		cv::INTER_LINEAR,
		cv::BORDER_CONSTANT,
		cv::Scalar()
	);

	for (int i = 0; i < 3; ++i)
	{
		cv::circle(dst, dstTri[i], 5, cv::Scalar(255, 0, 255), -1, cv::LINE_AA);//在对应位置绘制圆
	}

	cv::imshow("test", dst);
	cv::waitKey();

	for (int frame = 0;; ++frame)
	{
		cv::Point2f center(src.cols * 0.5f, src.rows * 0.5f);
		double angle = frame * 3 % 360, scale = (cos((angle - 60) * CV_PI / 180) + 1.05) * 0.8;
		cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, scale); //计算旋转图像对应的映射矩阵

		cv::warpAffine(
			src,
			dst,
			rot_mat,
			src.size(),
			cv::INTER_LINEAR,
			cv::BORDER_CONSTANT,
			cv::Scalar()
		);
		cv::imshow("test", dst);
		if (cv::waitKey(30) >= 0)
		{
			break;
		}
	}

	return 0;
}



#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

// 使用cv::threshold()函数对三个通道求平均
void sum_rgb(const cv::Mat& src, cv::Mat& dst)
{
	// 将图像分为rgb平面
	vector<cv::Mat> planes;
	cv::split(src, planes);

	cv::Mat b = planes[0], g = planes[1], r = planes[2], s;

	// 将rgb通道平均加权。s为输出图像
	cv::addWeighted(r, 1. / 3, g, 1. / 3, 0.0, s); //函数实现如下操作
	//s = r / 3 + g / 3;
	cv::addWeighted(s, 1., b, 1. / 3, 0.0, s);

	cv::threshold(s, dst, 100, 100, cv::THRESH_TRUNC);//截断大于100的值

}
// 组合和阈值图像平面的替代方法
void sum_rgb1(const cv::Mat& src, cv::Mat& dst)
{
	vector<cv::Mat> planes;
	cv::split(src, planes);

	cv::Mat b = planes[0], g = planes[1], r = planes[2];

	// 累积各个通道，结合阈值。

	cv::Mat s = cv::Mat::zeros(b.size(), CV_32F);
	cv::accumulate(b, s);
	cv::accumulate(g, s);
	cv::accumulate(r, s);

	//截断大于100的值
	cv::threshold(s, s, 100, 100, cv::THRESH_TRUNC);
	s.convertTo(dst, b.type());

}
int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "请输入图像" << endl;
		return -1;
	}
	
	cv::Mat src = cv::imread(argv[1]), dst;
	if (src.empty())
	{
		cout << "输入图像有误" << endl;
		return -1;
	}
	sum_rgb(src, dst);

	cv::namedWindow(argv[1], 1);
	cv::imshow(argv[1], dst);
	cv::waitKey(0);

	return 0;
}
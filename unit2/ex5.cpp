//学习opencv书本示例代码：
//ckunlun
//2020.6.25
//例5 从摄像头中读取
//同一个对象可以读取视频文件，也可以连接摄像头读取

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{

	cv::namedWindow("example5", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap;
	if (argc == 1)
	{
		cap.open(0); // 打开摄像头,0为id号，如果只有一个摄像头，则默认为0
	}
	else
	{
		cap.open(argv[1]); //打开路劲上的文件
	}

	if (!cap.isOpened())
	{
		cerr << "Can not open capture." << endl;
		return -1;
	}

	cv::Mat frame;
	for (;;)
	{
		cap >> frame;
		if (frame.empty())
		{
			cout << "input error" << endl;
			break;
		}

		cv::imshow("example5", frame);
		if (cv::waitKey(33) >= 0)
			break;
	}

	cv::waitKey(0);

	cv::destroyAllWindows();
	cap.release();
	return 0;
}
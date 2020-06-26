//学习opencv书本课后作业
//ckunlun
//2020.6.25
//练习3：
//建立一个读取视频并存储降采样后彩色图像的程序。
//并显示处理前后的视频。

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	cv::namedWindow("input", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap(argv[1]);

	if (!cap.isOpened())
	{
		cerr << "Can not open capture." << endl;
		return -1;
	}

	double fps = cap.get(cv::CAP_PROP_FPS);
	cv::Size size(
		(int)cap.get(cv::CAP_PROP_FRAME_WIDTH) / 2,
		(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT) / 2
	);

	cv::Mat frame1, frame2;

	cv::VideoWriter writer;
	writer.open(argv[2], cv::CAP_OPENCV_MJPEG, fps, size); // 参数设置不正确则无法输出视频

	for (;;)
	{
		cap >> frame1;
		if (frame1.empty())
			break;
		cv::pyrDown(frame1, frame2);
		writer << frame2;
		cv::imshow("input", frame1);
		cv::imshow("output", frame2);

		char c = cv::waitKey(10);
		if (c == 27) //按esc退出
			break;
	}
	cap.release();
	//writer.release();
	cv::destroyAllWindows();
	return 0;
}

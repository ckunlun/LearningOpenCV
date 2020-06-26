//学习opencv书本示例代码：
//ckunlun
//2020.6.25
//例6 写入AVI文件
//一个完整的读取彩色视频并转化为对数极坐标视频的程序

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	cv::namedWindow("input", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output", cv::WINDOW_AUTOSIZE);

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

	double fps = cap.get(cv::CAP_PROP_FPS); //获取帧率
	cv::Size size( // 获取图像尺寸
		(int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)
	);

	// 写入视频
	cv::VideoWriter writer;
	writer.open(argv[2], cv::CAP_OPENCV_MJPEG, fps, size); // 使用MJPEG编码器。
	//CV_FOURCC('M', 'J', 'P', 'G')已被cv::CAP_OPENCV_MJPEG替换

	cv::Mat logpolar_frame, bgr_frame;
	for (;;)
	{
		cap >> bgr_frame;
		if (bgr_frame.empty())
			break;

		cv::imshow("input", bgr_frame);

		cv::logPolar(
			bgr_frame, //Input color frame
			logpolar_frame, //output frame
			cv::Point2f(   //Centerpoint for log-polar transformation
				bgr_frame.cols / 2, //x
				bgr_frame.rows / 2  //y
			),
			40, //Magnitude(scale parameter)
			cv::WARP_FILL_OUTLIERS //Fill outliers with 'zero'
		);

		cv::imshow("output", logpolar_frame);
		writer << logpolar_frame;
		
		char c = cv::waitKey(10);
		if (c == 27) //按esc退出
			break;
	}

	cap.release();
	writer.release();
	cv::destroyAllWindows();
	return 0;
}
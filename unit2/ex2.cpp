//学习opencv书本示例代码：
//ckunlun
//2020.6.25
//例2 一个简单的播放视频文件的opencv程序
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include <string>
using namespace std;

int main(int argc, char** argv) {

	cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);
	//在屏幕上显示一个窗口，用来显示图片，WINDOW_AUTOSIZE设置图像会被缩放适应窗口
	cv::VideoCapture cap; //读取视频的结构，这个结构可以打开和关闭很多类型的ffmpeg支持的文件。
	cap.open(string(argv[1])); //打开输入路劲下的视频。
	cv::Mat frame; //申明一个保存视频帧的结构
	for (;;) { //一直循环，直到视频读取完成
		cap >> frame;
		if (frame.empty()) //判断视频读取是否成功
			break;
		cv::imshow("Example2", frame); //显示图片
		if (cv::waitKey(33) >= 0) //等待用户输入，如果没有则跳过进入下一个循环。
			break;
	}
	cv::destroyWindow("Example1");  //销毁创建的窗口

	return 0;
}

//学习opencv书本示例代码：
//ckunlun
//2020.6.25
//例3 一个简单的播放视频文件的opencv程序,并实现跳转功能。
//任务是添加一个滑动条，使得用户可以进行视频跳转。为了执行更多的控制，我们将
//会允许用户通过按下S键来执行单步模式，以及按下R键来恢复连续视频播放模式，无论
//何时用户通过滑动条跳转到视频--个新的时间点，都会使用单步模式在那个点进行播放。

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int g_slider_position = 0; //存储滑动条的位置
int g_run = 1; //为正，指示停止在之前程序要播放多生张图片；为负，则表示处于连续视频播放模式。
int g_dontset = 0; //避免在调整进度条位置的时候触发单步模式
cv::VideoCapture g_cap;  //读取视频格式的变量


// 调整滑动条的时候的回调函数
// 传入参数表示希望进度条到达的位置。
void onTrackbarSlide(int pos, void*) {
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos); //移动进度条到希望的位置

	if (!g_dontset) // 设置是否进入单步模式
		g_run = 1;
	g_dontset = 0;
}

int main(int argc, char** argv) {

	cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
	//在屏幕上显示一个窗口，用来显示图片，WINDOW_AUTOSIZE设置图像会被缩放适应窗口

	g_cap.open(string(argv[1])); //打开输入路劲下的视频。
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT); //获取当前视频的帧数
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH); //获取当前视频的宽度
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT); //获取当前视频的宽度
	cout << "vide has " << frames << "frames of dimensions ("
		<< tmpw << ", " << tmph << ")." << endl;

	cv::createTrackbar("Position", "Example3", &g_slider_position, frames, onTrackbarSlide);
	// 创建滑动条，提供一个和滑动条绑定的变量以及在滑动条移动的时候的回调函数（不需要的时候可以输入NULL）


	cv::Mat frame; //申明一个保存视频帧的结构
	for (;;) { //一直循环，直到视频读取完成
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty()) //判断视频读取是否成功
				break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);// 获取当前帧的位置
			g_dontset = 1;

			cv::setTrackbarPos("Position", "Example3", current_pos); // 设置进度条位置
			cv::imshow("Example3", frame); //显示图片

			g_run -= 1;
		}

		char c = (char)cv::waitKey(10);
		if (c == 's') { //Single step
			g_run = 1;
			cout << "single step ,run = " << g_run << endl;
		}
		if (c == 'r') { //Single step
			g_run -= 1;
			cout << "Run mode ,run = " << g_run << endl;
		}
		if (c == 27)
			break;

	}


	cv::destroyWindow("Example3");  //销毁创建的窗口

	return 0;
}
//学习opencv书本示例代码：
//ckunlun
//2020.6.25
//例3 一个简单的播放视频文件的opencv程序,并实现跳转功能。
//任务是添加一个滑动条，使得用户可以进行视频跳转。为了执行更多的控制，我们将
//会允许用户通过按下S键来执行单步模式，以及按下R键来恢复连续视频播放模式，无论
//何时用户通过滑动条跳转到视频--个新的时间点，都会使用单步模式在那个点进行播放。

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int g_slider_position = 0; //存储滑动条的位置
int g_run = 1; //为正，指示停止在之前程序要播放多生张图片；为负，则表示处于连续视频播放模式。
int g_dontset = 0; //避免在调整进度条位置的时候触发单步模式
cv::VideoCapture g_cap;  //读取视频格式的变量


// 调整滑动条的时候的回调函数
// 传入参数表示希望进度条到达的位置。
void onTrackbarSlide(int pos, void*) {
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos); //移动进度条到希望的位置

	if (!g_dontset) // 设置是否进入单步模式
		g_run = 1;
	g_dontset = 0;
}

int main(int argc, char** argv) {

	cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
	//在屏幕上显示一个窗口，用来显示图片，WINDOW_AUTOSIZE设置图像会被缩放适应窗口

	g_cap.open(string(argv[1])); //打开输入路劲下的视频。
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT); //获取当前视频的帧数
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH); //获取当前视频的宽度
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT); //获取当前视频的宽度
	cout << "vide has " << frames << "frames of dimensions ("
		<< tmpw << ", " << tmph << ")." << endl;

	cv::createTrackbar("Position", "Example3", &g_slider_position, frames, onTrackbarSlide);
	// 创建滑动条，提供一个和滑动条绑定的变量以及在滑动条移动的时候的回调函数（不需要的时候可以输入NULL）


	cv::Mat frame; //申明一个保存视频帧的结构
	for (;;) { //一直循环，直到视频读取完成
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty()) //判断视频读取是否成功
				break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);// 获取当前帧的位置
			g_dontset = 1;

			cv::setTrackbarPos("Position", "Example3", current_pos); // 设置进度条位置
			cv::imshow("Example3", frame); //显示图片

			g_run -= 1;
		}

		char c = (char)cv::waitKey(10);
		if (c == 's') { //Single step
			g_run = 1;
			cout << "single step ,run = " << g_run << endl;
		}
		if (c == 'r') { //Single step
			g_run -= 1;
			cout << "Run mode ,run = " << g_run << endl;
		}
		if (c == 27)
			break;

	}


	cv::destroyWindow("Example3");  //销毁创建的窗口

	return 0;
}

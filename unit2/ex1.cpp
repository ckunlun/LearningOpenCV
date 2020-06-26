//学习opencv书本示例代码：
//ckunlun
//2020.6.25
//例1 一个简单的加载并显示图像的opencv程序

//#include <opencv2/opencv.hpp> //包含所有可能在openCV中用到的头文件
#include "opencv2/highgui/highgui.hpp" //使用必要的头文件来节省编译时间
using namespace cv; //指定命名空间。

int main(int argc, char** argv) {
	cv::Mat img = cv::imread(argv[1], -1); //读取图像，返回值为cv::Mat结构。
	if (img.empty()) //判断图像读取是否成功
		return -1;
	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	//在屏幕上显示一个窗口，用来显示图片，WINDOW_AUTOSIZE设置图像会被缩放适应窗口

	cv::imshow("Example1", img); //显示图片
	cv::waitKey(0); //等待键盘输入事件，如果输入>0,则会等待响应的ms事件后执行后续代码
					//如果输入<=0，则会一直等待，直到键盘被按下。
	cv::destroyWindow("Example1");  //销毁创建的窗口

	return 0;
}

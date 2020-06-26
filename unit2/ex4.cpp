//学习opencv书本示例代码：
//ckunlun
//2020.6.25
//例4 对图像进行变化的例程


#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

//加载图像并在显示之前平滑处理图像
void example4(const cv::Mat& image) {
	
	// 创建窗口来展示输入和输出图像
	cv::namedWindow("input image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output image", cv::WINDOW_AUTOSIZE);

	cv::imshow("input image", image);

	cv::Mat out;

	// 平滑滤波
	//Note: Could use GaussianBlur(), blur(), medianBlur() or bilateralFilter()
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3); 
	// 调用高斯模糊函数，且模糊核大小为5*5，两个3分别为在x和y方向上的标准差。
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	cv::imshow("output image", out);

	cv::waitKey(0);

	cv::destroyAllWindows(); // 销毁所有窗口

}

int main(int argc, char** argv) {
	cv::Mat img1, img2;

	cv::namedWindow("input image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output image", cv::WINDOW_AUTOSIZE);

	
	img1 = cv::imread(argv[1]);
	if (img1.empty()) {
		cout << "input error" << endl;
		return -1;
	}
	cv::imshow("input image", img1);
	
	// 使用cv::pyrDown()来创建一个新的图像，其宽高均为原始图像的一半
	//cv::pyrDown(img1, img2);

	//Canny边缘检测其输出一个单通道的灰度图像
	cv::Mat imgGray; // 生成的灰度图像
	cv::cvtColor(img1, imgGray, cv::COLOR_RGB2GRAY); // 从彩色图像转换为灰度图像
	cv::Canny(imgGray, img2, 10, 100, 3, true); 
	// 使用Canny算法进行边缘检测。输入参数如下：
	// InputArray类型的image，输入图像，即源图像，填Mat类的对象即可，且需为单通道8位图像。
	// OutputArray类型的edges，输出的边缘图，需要和源图片有一样的尺寸和类型。
	// double类型的threshold1，第一个滞后性阈值【低阈值】。值越大，找到的边缘越少
	// double类型的threshold2，第二个滞后性阈值【高阈值】。
	// int类型的apertureSize，表示应用Sobel算子的孔径大小，其有默认值3。
	// bool类型的L2gradient，一个计算图像梯度幅值的标识，有默认值false。
	

	//读取图像像素值
	int x = 16, y = 32;
	cv::Vec3b intensity = img1.at<cv::Vec3b>(y, x);

	//获取对应的rgb值
	//也可以直接写成cv::Vec3b intensity = img1.at<cv::Vec3b>(y, x)[0];
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];
	
	cout << "At (x, y) = (" << x << ", " << y << "),"
		<< "(blue, green, red) = (" << (unsigned int)blue <<
		", " << (unsigned int)red << ", " <<
		(unsigned int)green << ")" << endl;

	cout << "Gray pixel there is " << (unsigned int)
		imgGray.at<uchar>(y, x) << endl;

	// 改变像素值
	imgGray.at<uchar>(y, x) = 128;

	cout << "Gray pixel there is " << (unsigned int)
		imgGray.at<uchar>(y, x) << endl;
	//cv::imshow("output image", img2);
	
	
	cv::waitKey(0);

	cv::destroyAllWindows(); // 销毁所有窗口

	return 0;

}
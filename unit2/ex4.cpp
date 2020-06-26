//ѧϰopencv�鱾ʾ�����룺
//ckunlun
//2020.6.25
//��4 ��ͼ����б仯������


#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

//����ͼ������ʾ֮ǰƽ������ͼ��
void example4(const cv::Mat& image) {
	
	// ����������չʾ��������ͼ��
	cv::namedWindow("input image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output image", cv::WINDOW_AUTOSIZE);

	cv::imshow("input image", image);

	cv::Mat out;

	// ƽ���˲�
	//Note: Could use GaussianBlur(), blur(), medianBlur() or bilateralFilter()
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3); 
	// ���ø�˹ģ����������ģ���˴�СΪ5*5������3�ֱ�Ϊ��x��y�����ϵı�׼�
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	cv::imshow("output image", out);

	cv::waitKey(0);

	cv::destroyAllWindows(); // �������д���

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
	
	// ʹ��cv::pyrDown()������һ���µ�ͼ�����߾�Ϊԭʼͼ���һ��
	//cv::pyrDown(img1, img2);

	//Canny��Ե��������һ����ͨ���ĻҶ�ͼ��
	cv::Mat imgGray; // ���ɵĻҶ�ͼ��
	cv::cvtColor(img1, imgGray, cv::COLOR_RGB2GRAY); // �Ӳ�ɫͼ��ת��Ϊ�Ҷ�ͼ��
	cv::Canny(imgGray, img2, 10, 100, 3, true); 
	// ʹ��Canny�㷨���б�Ե��⡣����������£�
	// InputArray���͵�image������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɣ�����Ϊ��ͨ��8λͼ��
	// OutputArray���͵�edges������ı�Եͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
	// double���͵�threshold1����һ���ͺ�����ֵ������ֵ����ֵԽ���ҵ��ı�ԵԽ��
	// double���͵�threshold2���ڶ����ͺ�����ֵ������ֵ����
	// int���͵�apertureSize����ʾӦ��Sobel���ӵĿ׾���С������Ĭ��ֵ3��
	// bool���͵�L2gradient��һ������ͼ���ݶȷ�ֵ�ı�ʶ����Ĭ��ֵfalse��
	

	//��ȡͼ������ֵ
	int x = 16, y = 32;
	cv::Vec3b intensity = img1.at<cv::Vec3b>(y, x);

	//��ȡ��Ӧ��rgbֵ
	//Ҳ����ֱ��д��cv::Vec3b intensity = img1.at<cv::Vec3b>(y, x)[0];
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];
	
	cout << "At (x, y) = (" << x << ", " << y << "),"
		<< "(blue, green, red) = (" << (unsigned int)blue <<
		", " << (unsigned int)red << ", " <<
		(unsigned int)green << ")" << endl;

	cout << "Gray pixel there is " << (unsigned int)
		imgGray.at<uchar>(y, x) << endl;

	// �ı�����ֵ
	imgGray.at<uchar>(y, x) = 128;

	cout << "Gray pixel there is " << (unsigned int)
		imgGray.at<uchar>(y, x) << endl;
	//cv::imshow("output image", img2);
	
	
	cv::waitKey(0);

	cv::destroyAllWindows(); // �������д���

	return 0;

}
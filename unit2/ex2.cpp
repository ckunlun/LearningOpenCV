//ѧϰopencv�鱾ʾ�����룺
//ckunlun
//2020.6.25
//��2 һ���򵥵Ĳ�����Ƶ�ļ���opencv����
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include <string>
using namespace std;

int main(int argc, char** argv) {

	cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);
	//����Ļ����ʾһ�����ڣ�������ʾͼƬ��WINDOW_AUTOSIZE����ͼ��ᱻ������Ӧ����
	cv::VideoCapture cap; //��ȡ��Ƶ�Ľṹ������ṹ���Դ򿪺͹رպܶ����͵�ffmpeg֧�ֵ��ļ���
	cap.open(string(argv[1])); //������·���µ���Ƶ��
	cv::Mat frame; //����һ��������Ƶ֡�Ľṹ
	for (;;) { //һֱѭ����ֱ����Ƶ��ȡ���
		cap >> frame;
		if (frame.empty()) //�ж���Ƶ��ȡ�Ƿ�ɹ�
			break;
		cv::imshow("Example2", frame); //��ʾͼƬ
		if (cv::waitKey(33) >= 0) //�ȴ��û����룬���û��������������һ��ѭ����
			break;
	}
	cv::destroyWindow("Example1");  //���ٴ����Ĵ���

	return 0;
}

//ѧϰopencv�鱾ʾ�����룺
//ckunlun
//2020.6.25
//��5 ������ͷ�ж�ȡ
//ͬһ��������Զ�ȡ��Ƶ�ļ���Ҳ������������ͷ��ȡ

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{

	cv::namedWindow("example5", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap;
	if (argc == 1)
	{
		cap.open(0); // ������ͷ,0Ϊid�ţ����ֻ��һ������ͷ����Ĭ��Ϊ0
	}
	else
	{
		cap.open(argv[1]); //��·���ϵ��ļ�
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
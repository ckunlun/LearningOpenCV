//ѧϰopencv�鱾ʾ�����룺
//ckunlun
//2020.6.25
//��6 д��AVI�ļ�
//һ�������Ķ�ȡ��ɫ��Ƶ��ת��Ϊ������������Ƶ�ĳ���

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

	double fps = cap.get(cv::CAP_PROP_FPS); //��ȡ֡��
	cv::Size size( // ��ȡͼ��ߴ�
		(int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)
	);

	// д����Ƶ
	cv::VideoWriter writer;
	writer.open(argv[2], cv::CAP_OPENCV_MJPEG, fps, size); // ʹ��MJPEG��������
	//CV_FOURCC('M', 'J', 'P', 'G')�ѱ�cv::CAP_OPENCV_MJPEG�滻

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
		if (c == 27) //��esc�˳�
			break;
	}

	cap.release();
	writer.release();
	cv::destroyAllWindows();
	return 0;
}
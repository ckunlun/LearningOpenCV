//ѧϰopencv�鱾ʾ�����룺
//ckunlun
//2020.6.25
//��3 һ���򵥵Ĳ�����Ƶ�ļ���opencv����,��ʵ����ת���ܡ�
//���������һ����������ʹ���û����Խ�����Ƶ��ת��Ϊ��ִ�и���Ŀ��ƣ����ǽ�
//�������û�ͨ������S����ִ�е���ģʽ���Լ�����R�����ָ�������Ƶ����ģʽ������
//��ʱ�û�ͨ����������ת����Ƶ--���µ�ʱ��㣬����ʹ�õ���ģʽ���Ǹ�����в��š�

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int g_slider_position = 0; //�洢��������λ��
int g_run = 1; //Ϊ����ָʾֹͣ��֮ǰ����Ҫ���Ŷ�����ͼƬ��Ϊ�������ʾ����������Ƶ����ģʽ��
int g_dontset = 0; //�����ڵ���������λ�õ�ʱ�򴥷�����ģʽ
cv::VideoCapture g_cap;  //��ȡ��Ƶ��ʽ�ı���


// ������������ʱ��Ļص�����
// ���������ʾϣ�������������λ�á�
void onTrackbarSlide(int pos, void*) {
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos); //�ƶ���������ϣ����λ��

	if (!g_dontset) // �����Ƿ���뵥��ģʽ
		g_run = 1;
	g_dontset = 0;
}

int main(int argc, char** argv) {

	cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
	//����Ļ����ʾһ�����ڣ�������ʾͼƬ��WINDOW_AUTOSIZE����ͼ��ᱻ������Ӧ����

	g_cap.open(string(argv[1])); //������·���µ���Ƶ��
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT); //��ȡ��ǰ��Ƶ��֡��
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH); //��ȡ��ǰ��Ƶ�Ŀ��
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT); //��ȡ��ǰ��Ƶ�Ŀ��
	cout << "vide has " << frames << "frames of dimensions ("
		<< tmpw << ", " << tmph << ")." << endl;

	cv::createTrackbar("Position", "Example3", &g_slider_position, frames, onTrackbarSlide);
	// �������������ṩһ���ͻ������󶨵ı����Լ��ڻ������ƶ���ʱ��Ļص�����������Ҫ��ʱ���������NULL��


	cv::Mat frame; //����һ��������Ƶ֡�Ľṹ
	for (;;) { //һֱѭ����ֱ����Ƶ��ȡ���
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty()) //�ж���Ƶ��ȡ�Ƿ�ɹ�
				break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);// ��ȡ��ǰ֡��λ��
			g_dontset = 1;

			cv::setTrackbarPos("Position", "Example3", current_pos); // ���ý�����λ��
			cv::imshow("Example3", frame); //��ʾͼƬ

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


	cv::destroyWindow("Example3");  //���ٴ����Ĵ���

	return 0;
}
//ѧϰopencv�鱾ʾ�����룺
//ckunlun
//2020.6.25
//��3 һ���򵥵Ĳ�����Ƶ�ļ���opencv����,��ʵ����ת���ܡ�
//���������һ����������ʹ���û����Խ�����Ƶ��ת��Ϊ��ִ�и���Ŀ��ƣ����ǽ�
//�������û�ͨ������S����ִ�е���ģʽ���Լ�����R�����ָ�������Ƶ����ģʽ������
//��ʱ�û�ͨ����������ת����Ƶ--���µ�ʱ��㣬����ʹ�õ���ģʽ���Ǹ�����в��š�

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int g_slider_position = 0; //�洢��������λ��
int g_run = 1; //Ϊ����ָʾֹͣ��֮ǰ����Ҫ���Ŷ�����ͼƬ��Ϊ�������ʾ����������Ƶ����ģʽ��
int g_dontset = 0; //�����ڵ���������λ�õ�ʱ�򴥷�����ģʽ
cv::VideoCapture g_cap;  //��ȡ��Ƶ��ʽ�ı���


// ������������ʱ��Ļص�����
// ���������ʾϣ�������������λ�á�
void onTrackbarSlide(int pos, void*) {
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos); //�ƶ���������ϣ����λ��

	if (!g_dontset) // �����Ƿ���뵥��ģʽ
		g_run = 1;
	g_dontset = 0;
}

int main(int argc, char** argv) {

	cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
	//����Ļ����ʾһ�����ڣ�������ʾͼƬ��WINDOW_AUTOSIZE����ͼ��ᱻ������Ӧ����

	g_cap.open(string(argv[1])); //������·���µ���Ƶ��
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT); //��ȡ��ǰ��Ƶ��֡��
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH); //��ȡ��ǰ��Ƶ�Ŀ��
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT); //��ȡ��ǰ��Ƶ�Ŀ��
	cout << "vide has " << frames << "frames of dimensions ("
		<< tmpw << ", " << tmph << ")." << endl;

	cv::createTrackbar("Position", "Example3", &g_slider_position, frames, onTrackbarSlide);
	// �������������ṩһ���ͻ������󶨵ı����Լ��ڻ������ƶ���ʱ��Ļص�����������Ҫ��ʱ���������NULL��


	cv::Mat frame; //����һ��������Ƶ֡�Ľṹ
	for (;;) { //һֱѭ����ֱ����Ƶ��ȡ���
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty()) //�ж���Ƶ��ȡ�Ƿ�ɹ�
				break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);// ��ȡ��ǰ֡��λ��
			g_dontset = 1;

			cv::setTrackbarPos("Position", "Example3", current_pos); // ���ý�����λ��
			cv::imshow("Example3", frame); //��ʾͼƬ

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


	cv::destroyWindow("Example3");  //���ٴ����Ĵ���

	return 0;
}

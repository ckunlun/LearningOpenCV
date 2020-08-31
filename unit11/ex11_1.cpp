#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

//����任
int main(int argc, char** argv)
{
	cv::Mat src = cv::imread(argv[1], 1);
	if (src.empty())
	{
		return -1;
	}
	cv::Point2f srcTri[] = { //ԭʼͼ�������
		cv::Point2f(0, 0), //dst Top left
		cv::Point2f(src.cols - 1, 0), //dst Top right
		cv::Point2f(0, src.rows - 1) //dit bottem left
	};

	cv::Point2f dstTri[] = { //ת����ͼ�������
		cv::Point2f(src.cols * 0.f, src.rows * 0.33f), //dst Top left
		cv::Point2f(src.cols * 0.85f, src.rows * 0.25f), //dst Top right
		cv::Point2f(src.cols * 0.15f, src.rows * 0.7f) //dit bottem left
	};

	cv::Mat wrap_mat = cv::getAffineTransform(srcTri, dstTri); //����ӳ�����
	cv::Mat dst;
	cv::warpAffine( //����ͬӳ���õ�ͼ����
		src,
		dst,
		wrap_mat,
		src.size(), //Ŀ��ͼ���С
		cv::INTER_LINEAR,
		cv::BORDER_CONSTANT,
		cv::Scalar()
	);

	for (int i = 0; i < 3; ++i)
	{
		cv::circle(dst, dstTri[i], 5, cv::Scalar(255, 0, 255), -1, cv::LINE_AA);//�ڶ�Ӧλ�û���Բ
	}

	cv::imshow("test", dst);
	cv::waitKey();

	for (int frame = 0;; ++frame)
	{
		cv::Point2f center(src.cols * 0.5f, src.rows * 0.5f);
		double angle = frame * 3 % 360, scale = (cos((angle - 60) * CV_PI / 180) + 1.05) * 0.8;
		cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, scale); //������תͼ���Ӧ��ӳ�����

		cv::warpAffine(
			src,
			dst,
			rot_mat,
			src.size(),
			cv::INTER_LINEAR,
			cv::BORDER_CONSTANT,
			cv::Scalar()
		);
		cv::imshow("test", dst);
		if (cv::waitKey(30) >= 0)
		{
			break;
		}
	}

	return 0;
}

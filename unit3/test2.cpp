//ѧϰopencv�鱾�κ���ҵ
//ckunlun
//2020.6.30
//��ϰ2��
//�����;����������

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main()
{
    cv::Matx33f myMat(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9); //����һ��3*3�ľ���
    cv::Matx31f myMec(1.1, 2.2, 3.3); //����һ��3ά����
    cv::Vec3f myVec(1.1, 2.2, 3.3); //����һ��3ά����

    cv::Matx31f zero31 = cv::Matx31f::zeros(); //����һ��ȫ�����
    zero31 = myMat * myVec; //����˷�
    zero31 = myMat * myMec; //����˷�

    cout << myMat << endl << zero31 << endl;
    
 /*   ���н����
    [1.1, 2.2, 3.3;
    4.4000001, 5.5, 6.5999999;
    7.6999998, 8.8000002, 9.8999996]
    [16.939999;
    38.720001;
    60.5]*/
    return 0;

}


//ѧϰopencv�鱾�κ���ҵ
//ckunlun
//2020.6.30
//���ĵ�Ԫ��4-2

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    const int n_mat_size = 5;
    const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
    cv::Mat n_mat0(3, n_mat_sz, CV_32FC1);
    cv::Mat n_mat1(3, n_mat_sz, CV_32FC1);

    cv::RNG rng;
    rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);//ʹ��0-1֮�������������������䡣
    rng.fill(n_mat1, cv::RNG::UNIFORM, 0.f, 1.f);//ʹ��0-1֮�������������������䡣

    const cv::Mat* arrays[] = { &n_mat0, &n_mat1, 0 };//����һ��c���Է�������ָ�룬���а�����Ҫ���������飬
                                            //�ұ�����0��NULL��β��
    cv::Mat my_planes[2];//��һ����Ϊ��ο���C����cv::Mat���飬�Ӷ�ͨ�������е�����
    cv::NAryMatIterator it(arrays, my_planes);//����NAryMatIterator��������

    //�����������
    //����ÿ�����������ԣ�it.planes[i]��arrays�еĵ�i������ĵ�ǰplane��
    float s = 0.f;//����ƽ��ĺ�
    int n = 0;//plane����Ŀ
    for (int p = 0; p < it.nplanes; p++, ++it) {
        s += cv::sum(it.planes[0])[0];//����ֵ�����ڸ���ͨ������ʾn_mat0
        s += cv::sum(it.planes[1])[0];//����ֵ�����ڸ���ͨ������ʾn_mat1
        n++;
    }
    //it.size����ʾ��
    cout << it.size << endl;//���Ϊ5*5*5=125.
    return 0;
}


//ѧϰopencv�鱾�κ���ҵ
//ckunlun
//2020.6.30
//���ĵ�Ԫ��4-1

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    const int n_mat_size = 5;
    const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
    cv::Mat n_mat(3, n_mat_sz, CV_32FC1);

    cv::RNG rng;
    rng.fill(n_mat, cv::RNG::UNIFORM, 0.f, 1.f);//ʹ��0-1֮�������������������䡣

    const cv::Mat* arrays[] = { &n_mat, 0 };//����һ��c���Է�������ָ�룬���а�����Ҫ���������飬
                                            //�ұ�����0��NULL��β��
    cv::Mat my_planes[1];//��һ����Ϊ��ο���C����cv::Mat���飬�Ӷ�ͨ�������е�����
    cv::NAryMatIterator it(arrays, my_planes);//����NAryMatIterator��������

    //����������m0��m1�ĺͣ���������ŵ�m2�С�
    //����ÿ�����������ԣ�it.planes[i]��arrays�еĵ�i������ĵ�ǰplane��
    float s = 0.f;//����ƽ��ĺ�
    int n = 0;//plane����Ŀ
    for (int p = 0; p < it.nplanes; p++, ++it) {
        s += cv::sum(it.planes[0])[0];//����ֵ�����ڸ���ͨ����
        n++;
    }

    return 0;
}


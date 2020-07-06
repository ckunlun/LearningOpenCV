//ѧϰopencv�鱾�κ���ҵ
//ckunlun
//2020.7.6
//���ĵ�Ԫ��4-3
//��ӡϡ������Ԫ��
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    //����һ��10*10��ϡ�����
    int size[] = { 10, 10 };
    cv::SparseMat sm(2, size, CV_32F);

    for (int i = 0; i < 10; i++) { //�������
        int idx[2];
        idx[0] = size[0] * rand();
        idx[1] = size[1] * rand();

        sm.ref<float>(idx) += 1.0f;
    }

    //��ӡ��0ֵ
    cv::SparseMatConstIterator_<float> it = sm.begin<float>();
    cv::SparseMatConstIterator_<float> it_end = sm.end<float>();

    for (; it != it_end; ++it) {
        const cv::SparseMat::Node* node = it.node();
        cout << "(" << node->idx[0] << ", " << node->idx[1] << ")" << *it << endl;
    }

    //��ͨ����
    //cv::Mat m(10, 10, CV_32FC2);
    //m.at<Vec2f>(i0, i1) = cv::Vec2f(x, y);//����Ԫ�ط�����Ҫָ����������͡�

    ////ģ�����
    //cv::Mat_<Vec2f> m(10, 10);
    //m.at(i0, i1) = cv::Vec2f(x, y);
    ////����
    //m(i0, i1) = cv::Vec2f(x, y);

    return 0;
}


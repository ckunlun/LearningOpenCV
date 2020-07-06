//学习opencv书本课后作业
//ckunlun
//2020.7.6
//第四单元例4-3
//打印稀疏矩阵的元素
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    //创建一个10*10的稀疏矩阵
    int size[] = { 10, 10 };
    cv::SparseMat sm(2, size, CV_32F);

    for (int i = 0; i < 10; i++) { //填充数组
        int idx[2];
        idx[0] = size[0] * rand();
        idx[1] = size[1] * rand();

        sm.ref<float>(idx) += 1.0f;
    }

    //打印非0值
    cv::SparseMatConstIterator_<float> it = sm.begin<float>();
    cv::SparseMatConstIterator_<float> it_end = sm.end<float>();

    for (; it != it_end; ++it) {
        const cv::SparseMat::Node* node = it.node();
        cout << "(" << node->idx[0] << ", " << node->idx[1] << ")" << *it << endl;
    }

    //普通矩阵
    //cv::Mat m(10, 10, CV_32FC2);
    //m.at<Vec2f>(i0, i1) = cv::Vec2f(x, y);//独立元素访问需要指明矩阵的类型。

    ////模板矩阵
    //cv::Mat_<Vec2f> m(10, 10);
    //m.at(i0, i1) = cv::Vec2f(x, y);
    ////或者
    //m(i0, i1) = cv::Vec2f(x, y);

    return 0;
}


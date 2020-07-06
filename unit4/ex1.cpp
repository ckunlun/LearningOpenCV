//学习opencv书本课后作业
//ckunlun
//2020.6.30
//第四单元数组迭代器之前的示例代码
//c++的数据处理
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    //cv::Mat m;

    ////创建一个3行10列3通道32位浮点型的数据
    //m.create(3, 10, CV_32FC3);
    //
    ////设置第一个通道的值为1.0，第二个通道的值为0.0，第三个通道的值为1.0
    //m.setTo(cv::Scalar(1.0f, 0.0f, 1.0f));


    ////上述代码等效于
    //cv::Mat m1(3, 10, CV_32FC3, cv::Scalar(1.0f, 0.0f, 1.0f));

    //数组元素的访问：
    //cv::Mat m = cv::Mat::eye(10, 10, CV_32FC1);
    //
    //cout << m.at<float>(3, 3) << endl;  //直接访问数组元素。

    cv::Mat m0 = cv::Mat::eye(10, 10, CV_32FC2); //此函数存在问题。

    cout << m0.at<Vec2f>(1, 1)[0] << endl;

    //复数数组的访问
    //cv::Mat m1 = cv::Mat::eye(10, 10, cv::DataType<cv::Complexf>::generic_type);
    //cout << m1.at<cv::Complexf>(3, 3).re << endl; //访问存在问题，后期修复
    
    //使用迭代器访问数组元素，查找L2距离最长的元素。
    int sz[3] = { 4, 4, 4 };
    cv::Mat m(3, sz, CV_32FC3); //3为数组，大小为4*4*4
    cv::randu(m, -1.0f, 1.0f); //用随机数进行填充，随机数范围为-1.0到1.0

    float max = 0.0f; //初始化最小值
    cv::MatConstIterator_<cv::Vec3f> it = m.begin<cv::Vec3f>(); //初始化迭代器

    while (it != m.end<cv::Vec3f>()) {
        float len2 = (*it)[0] * (*it)[0] + (*it)[1] * (*it)[1] + (*it)[2] * (*it)[2];
        if (len2 > max)
            max = len2;
        it++;
    }
    cout << max << endl;

    return 0;
}


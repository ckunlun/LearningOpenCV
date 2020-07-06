//学习opencv书本课后作业
//ckunlun
//2020.6.30
//第四单元例4-2

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
    rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);//使用0-1之间的随机数对数组进行填充。
    rng.fill(n_mat1, cv::RNG::UNIFORM, 0.f, 1.f);//使用0-1之间的随机数对数组进行填充。

    const cv::Mat* arrays[] = { &n_mat0, &n_mat1, 0 };//创建一个c语言风格的数组指针，其中包含想要迭代的数组，
                                            //且必须以0或NULL结尾。
    cv::Mat my_planes[2];//另一个作为面参考的C风格的cv::Mat数组，从而通过它进行迭代。
    cv::NAryMatIterator it(arrays, my_planes);//创建NAryMatIterator迭代器。

    //两个数组相加
    //对于每个迭代器而言，it.planes[i]是arrays中的第i个数组的当前plane。
    float s = 0.f;//所有平面的和
    int n = 0;//plane的数目
    for (int p = 0; p < it.nplanes; p++, ++it) {
        s += cv::sum(it.planes[0])[0];//返回值独立于各个通道。表示n_mat0
        s += cv::sum(it.planes[1])[0];//返回值独立于各个通道。表示n_mat1
        n++;
    }
    //it.size的演示。
    cout << it.size << endl;//结果为5*5*5=125.
    return 0;
}


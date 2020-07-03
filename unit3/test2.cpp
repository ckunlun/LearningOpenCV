//学习opencv书本课后作业
//ckunlun
//2020.6.30
//练习2：
//紧凑型矩阵和向量类

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main()
{
    cv::Matx33f myMat(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9); //生成一个3*3的矩阵
    cv::Matx31f myMec(1.1, 2.2, 3.3); //生成一个3维向量
    cv::Vec3f myVec(1.1, 2.2, 3.3); //生成一个3维向量

    cv::Matx31f zero31 = cv::Matx31f::zeros(); //创建一个全零矩阵
    zero31 = myMat * myVec; //矩阵乘法
    zero31 = myMat * myMec; //矩阵乘法

    cout << myMat << endl << zero31 << endl;
    
 /*   运行结果：
    [1.1, 2.2, 3.3;
    4.4000001, 5.5, 6.5999999;
    7.6999998, 8.8000002, 9.8999996]
    [16.939999;
    38.720001;
    60.5]*/
    return 0;

}


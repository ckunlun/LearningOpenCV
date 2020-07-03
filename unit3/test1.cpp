//学习opencv书本课后作业
//ckunlun
//2020.6.30
//练习1：
//c++的数据处理
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main()
{
    float test = - 1.5; 
    float testAbs = abs(test);
    //int testInt1 = fix(test); //朝零方向取整，报错提示无此函数
    int testInt2 = floor(test); //向下取整
    int testInt3 = ceil(test); //向上取整
    int testInt4 = round(test); //朝零方向取整

    srand((int)time(0)); //产生随机种子，把0换成NULL也行。
    //这样保证每次生成的随机数不一样。
    int myRand = rand();  //产生随机数

    //生成浮点数的cv::Point2f,把它转化成整形的cv::Point
    //把cv::Pointz转换成cv::Point2f
    cv::Point2f testPoint(1.1, 2.2); //值函数构造
    cv::Point pointInt(testPoint); //复制构造函数
    
    cout << test << endl << testAbs << endl;
    cout << testInt2 << endl << testInt3 << endl;
    cout << testInt4 << endl << myRand << endl;
    cout << testPoint << endl << pointInt << endl;

 /*   -1.5
      1.5
      - 2
      - 1
      - 2
      13831
      [1.1, 2.2]
      [1, 2]*/
    return 0;
    
}


// temp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // 创建一个新窗口
    cv::namedWindow("test1", 1);

    //读取图像数据
    cv::Mat img = cv::imread("../../test.jpg");
    
    cv::imshow("test1", img);

    while (true)
    {
        if (cv::waitKey(1000) == 27) //返回值为输入的按键
        {
            break;
        }
        cv::moveWindow("test1", 3, 3);
    }

    cv::destroyWindow("test1");//销毁窗口

    return 0;
}

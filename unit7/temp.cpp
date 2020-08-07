// temp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::RNG rng = cv::theRNG();
    std::cout << "An integer:" << (int)rng << std::endl;
    std::cout << "Another integer:" << int(rng) << std::endl;
    std::cout << "A float:" << (float)rng << std::endl;

    return 0;
}


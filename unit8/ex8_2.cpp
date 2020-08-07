// 例程8-2：使用cv::FileStorage创建一个a.yml参数文件
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>
int main()
{
    cv::FileStorage fs("test.yml", cv::FileStorage::WRITE);
    fs << "frameCount" << 5;
    time_t rawtime;
    time(&rawtime);
    fs << "calibrationDate" << asctime(localtime(&rawtime));

    cv::Mat cameraMatrix = (
        cv::Mat_<double>(3, 3) << 1000, 0, 320, 0, 1000, 240, 0, 0, 1
    );

    cv::Mat distCoeffs = (
        cv::Mat_<double>(5, 1) << 0.1, 0.01, -0.001, 0, 0
    );

    fs << "camerMatrix" << cameraMatrix << "distCoeffs" << distCoeffs;

    fs << "features" << "[";
    
    for (int i = 0; i < 3; i++)
    {
        int x = rand() % 640;
        int y = rand() % 480;
        uchar lbp = rand() % 256;

        fs << "{:" << "x" << x << "y" << y << "lbp" << "[:";
        for (int j = 0; j < 8; j++)
        {
            fs << ((lbp >> j) & 1);
        }
        fs << "]" << "}";
    }
    fs << "]";
    fs.release();
    return 0;
}


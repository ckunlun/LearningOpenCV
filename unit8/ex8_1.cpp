//例程8-1，演示获取视频信息。
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::VideoCapture cap("test.mp4");
    unsigned f = (unsigned)cap.get(cv::CAP_PROP_FOURCC);
    char fourcc[] = {
        (char)(f), //first character is lowest bits
        (char)(f >> 8), //next character is bits 8-15
        (char)(f >> 16),
        (char)(f >> 24),
        '\0'
    };
    std::cout << "************************" << std::endl;
    std::cout << fourcc << std::endl;
    return 0;
}


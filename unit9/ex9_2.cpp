// 使用鼠标回调完成绘制方框的小程序
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
// 定义鼠标回调
void my_mouse_callback(int event, int x, int y, int flag, void* param);

Rect box;
bool drawing_box = false;

void draw_box(Mat& img, Rect box)
{
    rectangle(
        img,
        box.tl(),//矩形的左上角
        box.br(),//矩形的右下角
        Scalar(0x00, 0x00, 0xff) //red
    );
}

int main()
{
    box = Rect(-1, -1, 0, 0);
    Mat image(200, 2000, CV_8UC3), temp;
    image.copyTo(temp);

    box = Rect(-1, -1, 0, 0);
    image = Scalar::all(0); //给值全为0

    cv::namedWindow("Box Example");

    cv::setMouseCallback(
        "Box Example",
        my_mouse_callback,
        (void*)&image
    );

    for (;;)
    {
        image.copyTo(temp);
        if (drawing_box)
        {
            draw_box(temp, box);
        }
        imshow("Box Example", temp);

        if (cv::waitKey(15) == 27)
        {
            break;
        }
    }
    return 0;
}

void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
    Mat& image = *(Mat*)param;
    switch (event)
    {
    case EVENT_MOUSEMOVE:
    {
        if (drawing_box)
        {
            box.width = x - box.x; //x和y发生了变化，从而计算w和h。
            box.height = y - box.y; //
        }
    }
    break;

    case EVENT_LBUTTONDOWN:
    {
        drawing_box = true;
        box = Rect(x, y, 0, 0); //x，y为鼠标事件的x和y坐标。
    }
    break;

    case EVENT_LBUTTONUP:
    {
        drawing_box = false;
        if (box.width < 0) //计算新的
        {
            box.x += box.width;
            box.width *= -1;
        }
        if (box.height < 0)
        {
            box.y += box.height;
            box.height *= -1;
        }
        draw_box(image, box);
    }
    break;
    }
}
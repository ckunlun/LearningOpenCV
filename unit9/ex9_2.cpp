// ʹ�����ص���ɻ��Ʒ����С����
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
// �������ص�
void my_mouse_callback(int event, int x, int y, int flag, void* param);

Rect box;
bool drawing_box = false;

void draw_box(Mat& img, Rect box)
{
    rectangle(
        img,
        box.tl(),//���ε����Ͻ�
        box.br(),//���ε����½�
        Scalar(0x00, 0x00, 0xff) //red
    );
}

int main()
{
    box = Rect(-1, -1, 0, 0);
    Mat image(200, 2000, CV_8UC3), temp;
    image.copyTo(temp);

    box = Rect(-1, -1, 0, 0);
    image = Scalar::all(0); //��ֵȫΪ0

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
            box.width = x - box.x; //x��y�����˱仯���Ӷ�����w��h��
            box.height = y - box.y; //
        }
    }
    break;

    case EVENT_LBUTTONDOWN:
    {
        drawing_box = true;
        box = Rect(x, y, 0, 0); //x��yΪ����¼���x��y���ꡣ
    }
    break;

    case EVENT_LBUTTONUP:
    {
        drawing_box = false;
        if (box.width < 0) //�����µ�
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
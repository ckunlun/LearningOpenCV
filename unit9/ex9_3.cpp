#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int g_switch_value = 1;
void switch_off_function()
{
	cout << "pause" << endl;
}
void switch_on_function()
{
	cout << "run" << endl;
}
void switch_callback(int position, void*)
{
	if (position == 0)
	{
		switch_off_function();
	}
	else
	{
		switch_on_function();
	}
}

int main(int argc, char** argv)
{
	Mat frame;
	VideoCapture g_capture;

	if (argc < 2 || !g_capture.open(argv[1]))
	{
		cout << "failed to open" << argv[1] << "video file" << endl;
		return -1;
	}

	namedWindow("example", 1);
	createTrackbar(
		"Switch",
		"example",
		&g_switch_value, //指向滑动条的指针
		1,
		NULL,
		switch_callback
	);

	for (;;)
	{
		if (g_switch_value)
		{
			g_capture >> frame;
			if (frame.empty())
				break;
			imshow("example", frame);
		}
		if (waitKey(10) == 27)
		{
			break;
		}
	}
	return 0;
}
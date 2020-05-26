/**
 * start with VideoCapture
 * author bruce sun
 * data MAY 25, 2020
 */

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
	Mat frame;

	//init VideoCapture
	VideoCapture cap;

	int index = 0;
	cap.open(index, CAP_ANY);
	if (!cap.isOpened()) {
		cerr << "ERROR! Unable to open camera\n";
		return -1;
	}
	cout << "width x height is " << cap.get(CAP_PROP_FRAME_WIDTH)
		<< "x" << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;
	cap.set(CAP_PROP_FRAME_WIDTH, 1280);
	cap.set(CAP_PROP_FRAME_HEIGHT, 720);

	cout << "width x height is " << cap.get(CAP_PROP_FRAME_WIDTH)
		<< "x" << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;

	cout << "Start grabbing" << endl
	   << "Press any key to terminate" << endl;
	Mat out;
	for (;;) {
		//wait for a new fram from camera and store it into 'frame'
		cap.read(frame);

		if (frame.empty()) {
			cerr << "ERROR! blank frame grabbed\n";
			break;
		}


		boxFilter(frame, out, -1, Size(5, 5));
		//show live and wait for a key with timeout long enough to show images
		imshow("Live", out);
		if (waitKey(5) >= 0)
			break;
	}

	return 0;
}

/**
 * start with VideoCapture
 * author bruce sun
 * data MAY 25, 2020
 */

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
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

	cout << "Start grabbing" << endl
	   << "Press any key to terminate" << endl;

	for (;;) {
		//wait for a new fram from camera and store it into 'frame'
		cap.read(frame);

		if (frame.empty()) {
			cerr << "ERROR! blank frame grabbed\n";
			break;
		}
		//show live and wait for a key with timeout long enough to show images
		imshow("Live", frame);
		if (waitKey(5) >= 0)
			break;
	}

	return 0;
}

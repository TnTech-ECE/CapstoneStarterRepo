#include <iostream>
#include <opencv2/opencv.hpp>

int Scan = 14;
double MU = 0.01;
int prevX = 0;
int prevY = 0;
int numTotalWhite = 0;

void threshold(cv::Mat &frame, int filterMatrix[640][640]) {
	numTotalWhite = 0;
	//iterate through all pixels
    for (int y = 0; y < frame.rows; ++y) {
        for (int x = 0; x < frame.cols; ++x){ 
        	//if intensity is higher than adaptive filter matrix
        	int luminance = (frame.at<cv::Vec3b>(y, x)[0] + frame.at<cv::Vec3b>(y, x)[1] + frame.at<cv::Vec3b>(y, x)[2]);
            	int filterVal = filterMatrix[x][y];
            if (luminance > filterVal && luminance > 220) {
                frame.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 255, 255); // White
                numTotalWhite++;
                filterMatrix[x][y] += ((luminance-filterVal) * 9* MU)+15;
                //printf("%d:  %d:   %d\n", filterVal, filterMatrix.at<uchar>(y, x), luminance);
            }
             else if (luminance - filterVal < -5){	//else if the difference is more than 10 dont update adaptive matrix
                frame.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 0); // Black
                filterMatrix[x][y] -= (luminance  *MU);
            }
            //else if it has gotten darker by 35 or less (something moved)
            else if(luminance - filterVal < -56 && luminance > 384){
            numTotalWhite++;
            	frame.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 255, 255); // White
            }
            //otherwise black
            else{
            	frame.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 0); // Black
            }
        }
    }
}

// Parameters: Frame pointer, Window size
// Returns: int x, int y, for window coordinates
std::vector<int> movingWindow(cv::Mat &frame, int size) {
    int xMax = 0, yMax = 0, maxWhite = 0;

    cv::Mat grayFrame;
    cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

	//scan all pixels (skipping some based on scan amount)
    for (int y = 0; y < frame.rows - size; y += Scan) {
        for (int x = 0; x < frame.cols - size; x += Scan) {
            int white_pixel_count = 0;
            for(int i = x; i < x + size; i++){
               for(int j = y; j < y + size; j++){
            	if((frame.at<cv::Vec3b>(j, i)[0]) != 0){
            		white_pixel_count++;	
            	}
            }
            }
            //printf("White Count: %d\n", frame.at<cv::Vec3b>(y, x)[0]);
            if (white_pixel_count > maxWhite && white_pixel_count > 250) {	//Make sure a significant part of the window is white
            	//update max location
                maxWhite = white_pixel_count;
                xMax = x;
                yMax = y;
            }
        }
    }

    return {xMax, yMax};
}


int main() {	
	//openCV Stuff
	int filterMatrix[640][640] = {0};
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera" << std::endl;
        return -1;
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    while (true) {		//main loop
        cv::Mat frame;
        cv::Mat normFrame;
        cap.read(frame);
        normFrame = frame.clone();
        //blur if needed
        //cv::GaussianBlur(frame, frame, cv::Size(7, 7), 0);
        //cv::medianBlur(frame, frame, 5);

        if (frame.empty()) {
            std::cerr << "Error: Frame is empty" << std::endl;
            break;
        }

        threshold(frame, filterMatrix);		//apply threshold to frame
	
	//use moving window function to get rectangle location
        std::vector<int> pos = movingWindow(frame, 30);
       	
       		//make sure the previous location is near the current one (reduces false positives) and make sure most is black
            if(abs(prevX - pos[0]) < 150 && abs(prevY - pos[1]) < 150 && (pos[0] != 0 && pos[1] != 0) && numTotalWhite < 80000){
            	cv::rectangle(normFrame, cv::Point(pos[0], pos[1]), cv::Point(pos[0] + 30, pos[1] + 30), cv::Scalar(0, 255, 0), 2);
            }
            prevX = pos[0];
            prevY = pos[1];
/*
	        // Create a kernel for extreme sharpening
        cv::Mat sharpKern = (cv::Mat_<float>(3,3) <<
                    -1.5, -1.5, -1.5,
                    -1.5, 60, -1.5,
                    -1.5, -1.5, -1.5);*/
                    

        //cv::filter2D(normFrame, normFrame, -1, sharpKern);
        cv::imshow("Golf Ball Detector", normFrame);

        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}


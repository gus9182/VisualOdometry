#include "VideoSource.hpp"

int main(){
  VideoSource cam(640,480);
  cv::Mat imBwFull(cam.getWidth()*2, cam.getHeight(), CV_8UC1);//erado o tamanho
  cv::Mat imBwL, imBwR, imRgbL, imRgbR;

  cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);
  while (true) {
    cam.grabRgbBw(imBwL, imBwR, imRgbL, imRgbR);
    cv::hconcat(imBwL, imBwR, imBwFull);
    imshow("Video", imBwFull);

    //waits for esc key to exit
    if(cv::waitKey(30) == 27) break;
  }
}

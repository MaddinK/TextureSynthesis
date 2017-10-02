#include <texture_synthesis/texture_synthesis.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


std::string GetMatDepth(const cv::Mat& mat)
{
  const int depth = mat.depth();

  switch (depth)
  {
    case CV_8U:  return "CV_8U";
    case CV_8S:  return "CV_8S";
    case CV_16U: return "CV_16U";
    case CV_16S: return "CV_16S";
    case CV_32S: return "CV_32S";
    case CV_32F: return "CV_32F";
    case CV_64F: return "CV_64F";
    default:
      return "Invalid depth type of matrix!";
  }
}

std::string GetMatType(const cv::Mat& mat)
{
  const int mtype = mat.type();

  switch (mtype)
  {
    case CV_8UC1:  return "CV_8UC1";
    case CV_8UC2:  return "CV_8UC2";
    case CV_8UC3:  return "CV_8UC3";
    case CV_8UC4:  return "CV_8UC4";

    case CV_8SC1:  return "CV_8SC1";
    case CV_8SC2:  return "CV_8SC2";
    case CV_8SC3:  return "CV_8SC3";
    case CV_8SC4:  return "CV_8SC4";

    case CV_16UC1: return "CV_16UC1";
    case CV_16UC2: return "CV_16UC2";
    case CV_16UC3: return "CV_16UC3";
    case CV_16UC4: return "CV_16UC4";

    case CV_16SC1: return "CV_16SC1";
    case CV_16SC2: return "CV_16SC2";
    case CV_16SC3: return "CV_16SC3";
    case CV_16SC4: return "CV_16SC4";

    case CV_32SC1: return "CV_32SC1";
    case CV_32SC2: return "CV_32SC2";
    case CV_32SC3: return "CV_32SC3";
    case CV_32SC4: return "CV_32SC4";

    case CV_32FC1: return "CV_32FC1";
    case CV_32FC2: return "CV_32FC2";
    case CV_32FC3: return "CV_32FC3";
    case CV_32FC4: return "CV_32FC4";

    case CV_64FC1: return "CV_64FC1";
    case CV_64FC2: return "CV_64FC2";
    case CV_64FC3: return "CV_64FC3";
    case CV_64FC4: return "CV_64FC4";

    default:
      return "Invalid type of matrix!";
  }
}


vision::TextureSynthesizer::TextureSynthesizer(cv::Mat& image_in, cv::Mat& mask_in):
    image(image_in),mask(mask_in) {};

vision::TextureSynthesizer::TextureSynthesizer() {
    image = 0;
    mask = 0;
}

void
vision::TextureSynthesizer::loadImages(cv::Mat &image_in, cv::Mat &mask_in) {
  image = image_in;
  mask = mask_in;
}

void
vision::TextureSynthesizer::setDebug(bool debug_val, std::string out_dir){
  debug_ = debug_val;
  out_dir_ = out_dir;
}

void
vision::TextureSynthesizer::debugPrint(std::string img_name, const cv::Mat& image_in){
  double min, max;
  cv::minMaxLoc(image_in, &min, &max);
  std::cout << "Depth of " << img_name << ": " << GetMatDepth(image_in) << std::endl;
  std::cout << "Type of " << img_name << ": " <<   GetMatType(image_in) << std::endl;
  std::cout << "Min value: " << min << " Max value: " << max <<std::endl <<std::endl;
  std::string print_nm = out_dir_ + img_name;
  cv::imwrite(print_nm, image_in);
}

void
vision::TextureSynthesizer::synthesize() {

  cv::Mat dx, dy, temp;
  cv::Mat img_gray;

  cv::cvtColor(image, img_gray, cv::COLOR_BGR2GRAY);
  cv::threshold(mask, mask, 2, 1, cv::THRESH_BINARY);

  if(debug_)
    debugPrint("mask.png", mask);

  if(debug_)
    debugPrint("gray_image.png", img_gray);

  cv::Sobel(img_gray, dx, CV_32F, 1,0);
  cv::Sobel(img_gray, dy, CV_32F, 0,1);

  if(debug_){
    debugPrint("dx1.png", dx);
    debugPrint("dy1.png", dy);
  }

  temp = dx; dx = -dy; dy = temp;

  if(debug_) {
    debugPrint("dx2.png", dx);
    debugPrint("dy2.png", dy);
  }

  cv::normalize(dx, dx, 0, 1);
  cv::normalize(dy, dy, 0, 1);

}

#include <opencv2/opencv.hpp>
#include <fstream>
#include "../include/texture_synthesis/texture_synthesis.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv )
{
  if( argc != 2)
  {
    cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
    return -1;
  }

  Mat image;
  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

  if(! image.data )                              // Check for invalid input
  {
    cout <<  "Could not open or find the image" << std::endl ;
    return -1;
  }

  vision::TextureSynthesizer ts;
  ts.foo();

  // Wait for a keystroke in the window
  return 0;
}
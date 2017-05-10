#include <opencv2/opencv.hpp>
#include <fstream>
#include "../include/texture_synthesis/texture_synthesis.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv )
{
  if( argc != 3)
  {
    cout <<" Usage: display_image ImageToLoadAndDisplay DirectionAndNameOfImage" << endl;
    return -1;
  }

  Mat image, img_msk;
  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file
  img_msk = imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);   // Read the file

  if(! image.data )                              // Check for invalid input
  {
    cout <<  "Could not open or find the image" << std::endl ;
    return -1;
  }

  // texture synthesizer
  vision::TextureSynthesizer ts;
  ts.foo();

  imwrite( argv[3], image);

  // Wait for a keystroke in the window
  return 0;
}
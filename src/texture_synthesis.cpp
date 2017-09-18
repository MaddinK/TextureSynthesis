#include <texture_synthesis/texture_synthesis.h>

void
vision::TextureSynthesizer::synthesize()
{

}

void
vision::TextureSynthesizer::loadImages(cv::Mat &image_in, cv::Mat &mask_in)
{
    image = image_in;
    mask = mask_in;
}

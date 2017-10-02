#ifndef __TEXTURE_SYNTHESIS_H_
#define __TEXTURE_SYNTHESIS_H_


#include <opencv2/core/mat.hpp>


namespace vision {
  class TextureSynthesizer {

  public:
    // Constructor
    TextureSynthesizer(cv::Mat& image_in, cv::Mat& mask_in);
    TextureSynthesizer();

    // functions
    void loadImages(cv::Mat& image_in, cv::Mat& mask_in);
    void synthesize();

    // helper
    void setDebug(bool debug_val, std::string out_dir);
    void debugPrint(std::string img_dir, const cv::Mat& image_in);

  private:
    cv::Mat image;
    cv::Mat mask;
    int patch_size;

    bool debug_;
    std::string out_dir_;
  };

}


#endif //__TEXTURE_SYNTHESIS_H_

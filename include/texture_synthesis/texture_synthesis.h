#ifndef __TEXTURE_SYNTHESIS_H_
#define __TEXTURE_SYNTHESIS_H_


#include <opencv2/core/mat.hpp>

namespace vision {
    class TextureSynthesizer {
      public:
        TextureSynthesizer(){
            image = 0;
            mask = 0;
            patch_size = 12;}
        void loadImages(cv::Mat& image_in, cv::Mat& mask_in);
        void synthesize();
    private:
        cv::Mat image;
        cv::Mat mask;
        int patch_size;
    };

}


#endif //__TEXTURE_SYNTHESIS_H_

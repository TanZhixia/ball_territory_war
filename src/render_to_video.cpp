#include <render_to_video.hpp>
#include <const.hpp>
void render_to_video(uint8_t* pixels, cv::VideoWriter& writer) {
    cv::Mat rgbaMat(HEIGHT, WIDTH, CV_8UC4, pixels);
    cv::Mat bgrMat;
    cv::cvtColor(rgbaMat, bgrMat, cv::COLOR_RGBA2BGR);
    writer.write(bgrMat);
}

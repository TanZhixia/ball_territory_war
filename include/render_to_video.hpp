#pragma once
#include <SFML/Graphics.hpp>
#include <opencv2/opencv.hpp>
void render_to_video(uint8_t* pixels, cv::VideoWriter& writer);

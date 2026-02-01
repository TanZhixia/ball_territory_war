#pragma once
#include <cstdint>
#include <const.hpp>

// 绘制一个颜色为rgb(r, g, b)的像素到(x, y), x和y从0开始
inline void draw_pixels(uint8_t* pixels, int x, int y, int r, int g, int b) {
    pixels[(y * WIDTH + x) * 4 + 0] = r;
    pixels[(y * WIDTH + x) * 4 + 1] = g;
    pixels[(y * WIDTH + x) * 4 + 2] = b;
    pixels[(y * WIDTH + x) * 4 + 3] = 255;
}

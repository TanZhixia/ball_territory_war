#pragma once
#include <const.hpp>
#include <color.hpp>

// 绘制一个颜色为rgb(r, g, b)的像素到(x, y), x和y从0开始
inline void draw_color_map(Color* pixels, int x, int y, Color c) {
    if (x >= 0 && x < HEIGHT && y >= 0 && y < HEIGHT) {
        pixels[(y * HEIGHT + x)] = c;
        return;
    }
}

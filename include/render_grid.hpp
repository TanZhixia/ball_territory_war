#pragma once
#include <const.hpp>
#include <draw_pixels.hpp>

// 绘制网格
inline void render_grid(uint8_t* pixels) {
    for (int i = 0; i < HEIGHT; i ++) {
        for (int j = 0; j <= 10; j ++) {
            draw_pixels(pixels, WIDTH - HEIGHT + HEIGHT / 10 * j - 3, i, 150, 150, 150);
            draw_pixels(pixels, WIDTH - HEIGHT + HEIGHT / 10 * j - 2, i, 150, 150, 150);
            draw_pixels(pixels, WIDTH - HEIGHT + HEIGHT / 10 * j - 1, i, 150, 150, 150);
        }
    }
    for (int i = 0; i < HEIGHT; i ++) {
        for (int j = 0; j < 10; j ++) {
            draw_pixels(pixels, i + WIDTH - HEIGHT, 0 + HEIGHT / 10 * j, 150, 150, 150);
            draw_pixels(pixels, i + WIDTH - HEIGHT, 1 + HEIGHT / 10 * j, 150, 150, 150);
            draw_pixels(pixels, i + WIDTH - HEIGHT, 2 + HEIGHT / 10 * j, 150, 150, 150);
        }
        draw_pixels(pixels, i + WIDTH - HEIGHT, HEIGHT - 1, 150, 150, 150);
        draw_pixels(pixels, i + WIDTH - HEIGHT, HEIGHT - 2, 150, 150, 150);
        draw_pixels(pixels, i + WIDTH - HEIGHT, HEIGHT - 3, 150, 150, 150);
    }
}

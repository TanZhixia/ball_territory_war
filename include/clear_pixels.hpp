#pragma once
#include <cstdint>
#include <draw_pixels.hpp>

// 清除像素
inline void clear_pixels(uint8_t* pixels) {
    for (int i = 0; i < WIDTH; i ++)
        for (int j = 0; j < HEIGHT; j ++)
            draw_pixels(pixels, i, j, 0, 0, 0);
}

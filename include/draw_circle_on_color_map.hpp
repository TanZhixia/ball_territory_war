#pragma once
#include <color.hpp>
#include <draw_color_map.hpp>
// 绘制一个圆
int draw_circle_on_color_map(Color* pixels, int x0, int y0, double rad, Color c, bool noColor = false);

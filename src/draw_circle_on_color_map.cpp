// /dev/null/draw_circle_on_color_map.cpp#L1-44
#include <draw_circle_on_color_map.hpp>
#include <iostream>

// 假设 draw_color_map 已经在同一个头文件或其它头文件里声明
//   void draw_color_map(Color* pixels, int x, int y, Color c);

int draw_circle_on_color_map(Color* pixels, int x0, int y0, double rad, Color c, bool noColor) {
    int result = 0;
    // ---- ① 辅助 lambda：在同一条 scan‑line 上一次性画完所有像素 ----
    auto draw_line = [&](int y, int xLeft, int xRight) {
        for (int x = xLeft; x <= xRight; ++x) {
            if (x >= 0 && x < HEIGHT && y >= 0 && y < HEIGHT) {
                Color col = c;
                col.convert();
                if (pixels[y + x * HEIGHT] != col) {
                    ++ result;
                }
                if (!noColor)
                    draw_color_map(pixels, x, y, c);
                col.convert();
            }
        }
    };

    // ---- ② 中点圆算法（整数版） + 实心填充 ----
    double x = 0;
    double y = rad;
    double d = 3 - 2 * rad;                 // 决策变量

    while (y >= x) {
        // 对称的四条水平扫描线（每条线把左右端点之间全部填满）
        // 1) y = y0 ± y  , x 范围 = [x0‑x , x0+x]
        draw_line(y0 + y, x0 - x, x0 + x);
        draw_line(y0 - y, x0 - x, x0 + x);
        // 2) y = y0 ± x  , x 范围 = [x0‑y , x0+y]
        draw_line(y0 + x, x0 - y, x0 + y);
        draw_line(y0 - x, x0 - y, x0 + y);

        // ---- ③ 更新决策变量 ----
        if (d < 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            --y;
        }
        ++x;
    }
    return result;
}

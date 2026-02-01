#pragma once
// 定义代码中需要用到的颜色
class Color {
    int r, g, b;
    Color(int r, int g, int b) : r(r), g(g), b(b) {}
    // 转换颜色, 球的颜色会比地板深一点, 所以要做之间的转换
    Color convert(Color c);
};

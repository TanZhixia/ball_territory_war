#pragma once
// 定义代码中需要用到的颜色
class Color {
    public:
        int r, g, b;
        Color(int r, int g, int b) : r(r), g(g), b(b) {}
        // 转换颜色, 球的颜色会比地板深一点, 所以要做之间的转换
        void convert();
        inline bool operator==(const Color& other) const {
            return r == other.r && g == other.g && b == other.b;
        }
        inline bool operator!=(const Color& other) const {
            return r != other.r || g != other.g || b != other.b;
        }
        inline void operator=(const Color& other) {
            r = other.r;
            g = other.g;
            b = other.b;
        }
};
namespace color {
    const Color NoneColor(-1, -1, -1);
    const Color Red(255, 0, 0);
    const Color BallRed(255, 100, 100);
    const Color Green(0, 255, 0);

    const Color Yellow(255, 255, 0);

    const Color Blue(0, 0, 255);
}

#pragma once
#include <cmath>
#include <const.hpp>
#include <color.hpp>
#include <draw_circle_on_color_map.hpp>
#include <list>
namespace ball {
    class Ball;
    inline std::list<Ball*> balls;
    class Ball {
        public:
            double x, y;
            int size;
            int angle;
            int speed;
            Color color {0, 0, 0};
            Ball(int x, int y, int size, int angle, Color c, int speed) : x(x), y(y), size(size), angle(angle), color(c), speed(speed) {
                balls.push_back(this);
            }
            void next() {
                if (x - 1 < getSize() || x > HEIGHT) {
                    angle = - angle;
                }
                if (y < getSize() || y > HEIGHT) {
                    angle = 180 - angle;
                }
                x += sin(angle * M_PI / 180.0) * speed;
                y += cos(angle * M_PI / 180.0) * speed;
            }
            double getSize() const {
                return (size + 999) / 1000.0;
            }
    };
    inline int renderBall(Color* pixels, Ball& ball, bool noColor = false) {
        return draw_circle_on_color_map(pixels, ball.x, ball.y, ball.getSize(), ball.color, noColor);
    }

}

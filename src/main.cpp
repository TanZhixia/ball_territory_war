#include <SFML/Graphics.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <const.hpp>
#include <render_to_video.hpp>
#include <render_to_window.hpp>
#include <draw_pixels.hpp>
#include <render_grid.hpp>
#include <vector>
#include <color.hpp>
#include <clear_pixels.hpp>
#include <draw_circle_on_color_map.hpp>
#include <draw_color_map.hpp>
#include <class/ball.hpp>
void draw_start_colors(Color* pixels) {
    draw_circle_on_color_map(pixels, HEIGHT / 10, HEIGHT / 10, HEIGHT / 10, color::Red);
    draw_circle_on_color_map(pixels, HEIGHT / 10, HEIGHT - HEIGHT / 10 - 1, HEIGHT / 10, color::Green);
    draw_circle_on_color_map(pixels, HEIGHT - HEIGHT / 10 - 1, HEIGHT / 10, HEIGHT / 10, color::Yellow);
    draw_circle_on_color_map(pixels, HEIGHT - HEIGHT / 10 - 1, HEIGHT - HEIGHT / 10 - 1, HEIGHT / 10, color::Blue);
}
int main() {
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), WINDOW_TITLE, WINDOW_STYLE);
    window.setFramerateLimit(FPS);
    sf::Texture texture;
    [[maybe_unused]] auto _ = texture.resize({WIDTH, HEIGHT});
    cv::VideoWriter writer(VIDEO_NAME, cv::VideoWriter::fourcc('a','v','c','1'), FPS, cv::Size(WIDTH, HEIGHT));
    std::vector<uint8_t> pixels(WIDTH * HEIGHT * 4, 255);
    std::vector<Color> colors(HEIGHT * HEIGHT, color::NoneColor);
    // for (int i = 20; i <= 500; i ++)
    //     for (int j = 20; j <= 1000; j ++)
    //         draw_color_map(colors.data(), i, j, color::Red);
    draw_start_colors(colors.data());
    int t = 0;
    while (window.isOpen()) {
        window.handleEvents(
            [&window] (const sf::Event::Closed&) {
                window.close();
            }
        );
        for (auto b : ball::balls) {
            ball::renderBall(colors.data(), *b);
        }
        std::memset(pixels.data(), 0, pixels.size());
        for (int i = 0; i < HEIGHT; i ++) {
            for (int j = 0; j < HEIGHT; j ++) {
                if (colors[j + i * HEIGHT] == color::NoneColor)
                    continue;
                Color& c = colors[j + i * HEIGHT];
                draw_pixels(pixels.data(), WIDTH - HEIGHT + i, j, c.r, c.g, c.b);
            }
        }
        render_grid(pixels.data());
        texture.update(pixels.data());
        render_to_window(window, texture);
        render_to_video(pixels.data(), writer);
        for (auto b : ball::balls) {
            b->color.convert();
            ball::renderBall(colors.data(), *b);
            b->color.convert();
        }
        for (auto it = ball::balls.begin(); it != ball::balls.end(); ) {
            auto b = *it;
            b->next();
            int s = ball::renderBall(colors.data(), *b, true);
            b->size -= s;
            if (b->size <= 0) {
                it = ball::balls.erase(it);
                continue;
            }
            it ++;
        }
        new ball::Ball(500, 500, 20000, t ++, color::BallRed, 10);
    }
    writer.release();
    return 0;
}

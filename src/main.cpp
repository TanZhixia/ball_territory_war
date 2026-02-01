#include <SFML/Graphics.hpp>
#include <opencv2/opencv.hpp>
#include <const.hpp>
#include <render_to_video.hpp>
#include <render_to_window.hpp>
#include <draw_pixels.hpp>
#include <render_grid.hpp>
#include <vector>
#include <color.hpp>
#include <clear_pixels.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), WINDOW_TITLE, WINDOW_STYLE);
    window.setFramerateLimit(FPS);
    sf::Texture texture;
    [[maybe_unused]] auto _ = texture.resize({WIDTH, HEIGHT});
    cv::VideoWriter writer(VIDEO_NAME, cv::VideoWriter::fourcc('a','v','c','1'), FPS, cv::Size(WIDTH, HEIGHT));
    std::vector<uint8_t> pixels(WIDTH * HEIGHT * 4, 255);
    while (window.isOpen()) {
        window.handleEvents(
            [&window] (const sf::Event::Closed&) {
                window.close();
            }
        );
        std::memset(pixels.data(), 255, pixels.size());
        clear_pixels(pixels.data());
        render_grid(pixels.data());
        texture.update(pixels.data());
        render_to_window(window, texture);
        render_to_video(pixels.data(), writer);
    }
    writer.release();
    return 0;
}

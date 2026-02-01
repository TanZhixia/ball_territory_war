#include <render_to_window.hpp>
#include <const.hpp>
void render_to_window(sf::RenderWindow& window, sf::Texture& texture) {
    sf::Sprite sprite(texture);
    sprite.setScale({1.0 * WINDOW_WIDTH / WIDTH, 1.0 * WINDOW_HEIGHT / HEIGHT});
    window.clear();
    window.draw(sprite);
    window.display();
}

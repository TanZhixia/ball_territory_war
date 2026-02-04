#include <color.hpp>
#include <stdexcept>
void Color::convert() {
    if (*this == color::Red) {
        *this = color::BallRed;
        return;
    }
    if (*this == color::BallRed) {
        *this = color::Red;
        return;
    }
    // throw std::runtime_error("Invalid color");
}

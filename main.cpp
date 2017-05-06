#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"

using namespace sf;
using namespace std;

int main() {
    /**< Window Creation */
    RenderWindow window(VideoMode(640, 480), "SFML Window");

    /**< Pong Paddle Definitions */
    RectangleShape _paddle1;
    _paddle1.setSize(Vector2f(15, 100));
    _paddle1.setOutlineColor(Color::White);
    _paddle1.setOutlineThickness(2);
    _paddle1.setPosition(20, 240);

    RectangleShape _paddle2;
    _paddle2 = _paddle1;
    _paddle2.setPosition(595, 240);

    Vector2f speed(0, 0.2);

    /**< Main Game Loop */
    while (window.isOpen())
    {
        /**< Event Loop Defintion and Detection */
        Event event;
        while (window.pollEvent(event))
        {
            /**< Check To See If The Window Is Closed (Useful for saving before exit) */
            if (event.type == Event::Closed)
                window.close();
        }

        /**< Barrier Defintions */
        Vector2f _topWindow(0, 0);


        /**< Move Up With Paddle 1 */
        if (Keyboard::isKeyPressed(Keyboard::W) && _paddle1.getPosition() != _topWindow)
            _paddle1.setPosition(_paddle1.getPosition() - speed);
        /**< Move Down With Paddle 1 */
        if (Keyboard::isKeyPressed(Keyboard::S))
            _paddle1.setPosition(_paddle1.getPosition() + speed);
        /**< Move Up With Paddle 2 */
        if (Keyboard::isKeyPressed(Keyboard::Up) && _paddle2.getPosition() != _topWindow)
            _paddle2.setPosition(_paddle2.getPosition() - speed);
        /**< Move Down With Paddle 2 */
        if (Keyboard::isKeyPressed(Keyboard::Down))
            _paddle2.setPosition(_paddle2.getPosition() + speed);

        /**< Change All the pixels on screen to a colour */
        window.clear(sf::Color::White);

        /**< Adds An Object To The Draw Bin */
        window.draw(_paddle1);
        window.draw(_paddle2);

        /**< Displays Whats in The Draw Bin */
        window.display();
    }
    return EXIT_SUCCESS;
}

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "window");

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(100.f, 100.f);
    circle.setRotation(45.f);

    sf::RectangleShape rectangle(sf::Vector2f(120.f, 80.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(400.f, 200.f);
    rectangle.setRotation(30.f);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.f, 0.f));
    triangle.setPoint(1, sf::Vector2f(100.f, 0.f));
    triangle.setPoint(2, sf::Vector2f(50.f, 100.f));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(600.f, 400.f);
    triangle.setRotation(90.f);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        window.display();
    }

    return 0;
}
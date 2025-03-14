#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

const float PI = 3.14159265;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

struct Tank {
    sf::RectangleShape body;
    float speed;
    float rotation;
    bool isAlive;

    Tank(sf::Vector2f size, sf::Color color, sf::Vector2f position, float default_rotation) {
        body.setSize(size);
        body.setFillColor(color);
        body.setPosition(position);
        body.setOrigin(size.x / 2, size.y / 2);

        speed = .05f;
        rotation = default_rotation;
        isAlive = true;
    }

    void move(float offset) {
        if (!isAlive) return;
        float angle = rotation * PI / 180.0f;
        body.move(offset * std::cos(angle), offset * std::sin(angle));
    }

    void rotate(float angle) {
        if (!isAlive) return;
        rotation += angle;
        body.setRotation(rotation);
    }
};

struct Bullet {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    bool isActive;

    Bullet(float radius, sf::Color color)
    {
        shape.setRadius(radius);
        shape.setFillColor(color);
        isActive = false;
    }

    void update() {
        if (!isActive) return;
        shape.move(velocity);
    }

    void reload() {
        isActive = false;
    }
};

bool checkCollision(const sf::FloatRect &rect1, const sf::FloatRect &rect2) {
    return rect1.intersects(rect2);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tank PvP");

    Tank tank1(sf::Vector2f(50, 30), sf::Color::Red, sf::Vector2f(100, 300), .0f);
    Tank tank2(sf::Vector2f(50, 30), sf::Color::Blue, sf::Vector2f(WINDOW_WIDTH - 100, 300), 180.f);

    Bullet bullet1(5, sf::Color::Red);
    Bullet bullet2(5, sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        
        if (tank1.isAlive) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) tank1.move(tank1.speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) tank1.move(-tank1.speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) tank1.rotate(-0.05f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) tank1.rotate(0.05f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) bullet1.reload();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !bullet1.isActive) { // && !bullet1.isActive
                bullet1.shape.setPosition(tank1.body.getPosition());
                bullet1.velocity = sf::Vector2f(
                    std::cos(tank1.rotation * PI / 180.0f) * 1.0f,
                    std::sin(tank1.rotation * PI / 180.0f) * 1.0f
                );
                bullet1.isActive = true;
            }
        }

        if (tank2.isAlive) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) tank2.move(tank2.speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) tank2.move(-tank2.speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) tank2.rotate(-0.05f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) tank2.rotate(0.05f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) bullet2.reload();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !bullet2.isActive) { // && !bullet2.isActive
                bullet2.shape.setPosition(tank2.body.getPosition());
                bullet2.velocity = sf::Vector2f(
                    std::cos(tank2.rotation * PI / 180.0f) * 1.0f,
                    std::sin(tank2.rotation * PI / 180.0f) * 1.0f
                );
                bullet2.isActive = true;
            }
        }
        
        bullet1.update();
        bullet2.update();
        
        if (bullet1.isActive && checkCollision(bullet1.shape.getGlobalBounds(), tank2.body.getGlobalBounds())) {
            std::cout << "RED TANK WIN" << std::endl;
            window.close();
        }
        if (bullet2.isActive && checkCollision(bullet2.shape.getGlobalBounds(), tank1.body.getGlobalBounds())) {
            std::cout << "BLUE TANK WIN!" << std::endl;
            window.close();
        }
        
        window.clear();

        if (tank1.isAlive) window.draw(tank1.body);
        if (tank2.isAlive) window.draw(tank2.body);

        if (bullet1.isActive) window.draw(bullet1.shape);
        if (bullet2.isActive) window.draw(bullet2.shape);

        window.display();
    }

    return 0;
}
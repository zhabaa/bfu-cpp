#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

const float PI = 3.14159265;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

bool checkCoords(const sf::Vector2f& coords) {
    if (0 > coords.x || coords.x > WINDOW_WIDTH || 0 > coords.y || coords.y > WINDOW_HEIGHT) {
        return false;
    }
    return true;
}

bool checkCollision(const sf::FloatRect &rect1, const sf::FloatRect &rect2) {
    return rect1.intersects(rect2);
}

struct Bullet {
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Bullet(const sf::Color color) {
        shape.setRadius(5);
        shape.setFillColor(sf::Color::White); // тут цвет
    }

    bool atScreen() {
        if (checkCoords(shape.getPosition())) { // проверка на вылет
            return false;
        }
        return true;
    }

    void update() {
        shape.move(velocity);

    }
};

struct Tank {
    sf::RectangleShape body;
    sf::Color color;
    bool isAlive;
    float speed;
    float rotation;
    
    std::vector<Bullet> bullets;
    const float rotationSpeed = 0.05f;

    Tank(sf::Vector2f size, sf::Color color, sf::Vector2f position, float default_rotation) {
        body.setSize(size);
        body.setFillColor(color);
        body.setPosition(position);
        body.setOrigin(size.x / 2, size.y / 2);

        speed = .05f;
        rotation = default_rotation;
        isAlive = true;
    }

    void move(bool forward) {
        if (!isAlive) return;
        float angle = rotation * PI / 180.0f;
        float offset = forward ? speed : -speed; // Проверка вперед назад
        body.move(offset * std::cos(angle), offset * std::sin(angle));
    }

    void rotate(bool left) {
        if (!isAlive) return;
        rotation += left ? -rotationSpeed : rotationSpeed; // Проверка лево право
        body.setRotation(rotation);
    }
    
    void shoot() {
        if (!isAlive) return;

        Bullet bullet(this -> color); // пока не роляет
        bullet.shape.setPosition(body.getPosition());

        bullet.velocity = sf::Vector2f(
            std::cos(rotation * PI / 180.0f) * 1.0f,
            std::sin(rotation * PI / 180.0f) * 1.0f
        );

        if (bullets.size() < 3) {
            bullets.push_back(bullet); // количество пупуль
            std::cout << "Bullet added! Total bullets: " << bullets.size() << std::endl; // Отладочный вывод
        }
    }
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tank PvP");

    Tank tank1(sf::Vector2f(50, 30), sf::Color::Red, sf::Vector2f(100, 300), .0f);
    // Tank tank2(sf::Vector2f(50, 30), sf::Color::Blue, sf::Vector2f(WINDOW_WIDTH - 100, 300), 180.f);


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        
        if (tank1.isAlive) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) tank1.move(true);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) tank1.move(false);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) tank1.rotate(true);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) tank1.rotate(false);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) tank1.shoot();
        }

        // if (tank2.isAlive) {
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) tank2.move(true);
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) tank2.move(false);
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) tank2.rotate(true);
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) tank2.rotate(false);
        //     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) bullet2.reload();

        //     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !bullet2.isActive) { // && !bullet2.isActive
        //     //     bullet2.shape.setPosition(tank2.body.getPosition());
        //     //     bullet2.velocity = sf::Vector2f(
        //     //         std::cos(tank2.rotation * PI / 180.0f) * 1.0f,
        //     //         std::sin(tank2.rotation * PI / 180.0f) * 1.0f
        //     //     );
        //     //     bullet2.isActive = true;
        //     // }
        // }


        for (auto it = tank1.bullets.begin(); it != tank1.bullets.end(); ) {
            it->update(); // Обновляем позицию пули
            if (!(it->atScreen())) {
                it = tank1.bullets.erase(it); // Удаляем пулю и получаем новый итератор
                std::cout << "Bullets deleted!" << std::endl;
            } else {
                ++it; // Переходим к следующей пуле
            }
        }

        std::cout << "Bullets count: " << tank1.bullets.size() << std::endl;
        for (const auto& bullet : tank1.bullets) {
            sf::Vector2f pos = bullet.shape.getPosition();
            std::cout << "Bullet position: (" << pos.x << ", " << pos.y << ")\n";
        }

        // if (bullet1.isActive && checkCollision(bullet1.shape.getGlobalBounds(), tank2.body.getGlobalBounds())) {
        //     std::cout << "RED TANK WIN" << std::endl;
        //     window.close();
        // }

        
        window.clear();

        if (tank1.isAlive) window.draw(tank1.body); // рисуем танк
        // if (tank2.isAlive) window.draw(tank2.body);

        for (const Bullet& bullet : tank1.bullets) {
            window.draw(bullet.shape); // рисуем пули
        }

        window.display();
    }

    return 0;
}
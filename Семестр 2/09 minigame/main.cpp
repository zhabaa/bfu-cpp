// TODO Кароче я в рот ебал эту хуйню что тут надо сделать
// 1) РАЗОБРАТЬСЯ С БЛЯДСКИМИ ПУЛЯМИ
// 2) подумать насчет перезарядки фр использовать многозадачность типа многопоточности потому что тут асинхрон отсасывает
// 3) По возможности добавить препятствия и коллизию танков, снарядов со стенами и краями
// 4) ну хз иди доп делай

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

    Bullet() {
        shape.setRadius(5);
        shape.setFillColor(sf::Color::White); // тут цвет
    }

    bool atScreen() {
        if (checkCoords(shape.getPosition())) return false;
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
    const float rotationSpeed = 0.05f;
    
    Bullet bullet;
    
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

        bullet.shape.setPosition(body.getPosition());

        bullet.velocity = sf::Vector2f(
            std::cos(rotation * PI / 180.0f) * 1.0f,
            std::sin(rotation * PI / 180.0f) * 1.0f
        );
    }

    // void update() {
        // bullet.update();
        // if (!bullet.atScreen()) {
        //     bullet = Bullet();
        // }
    // }
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tank PvP");

    Tank tank1(sf::Vector2f(50, 30), sf::Color::Red, sf::Vector2f(100, 300), .0f);
    Tank tank2(sf::Vector2f(50, 30), sf::Color::Cyan, sf::Vector2f(WINDOW_WIDTH - 100, 300), 180.f);

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
        if (tank2.isAlive) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) tank2.move(true);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) tank2.move(false);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) tank2.rotate(true);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) tank2.rotate(false);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) tank2.shoot();
        }

        if (checkCollision(tank1.bullet.shape.getGlobalBounds(), tank2.body.getGlobalBounds())) {
            std::cout << "RED TANK WIN" << std::endl;
            window.close();
        }        
        if (checkCollision(tank2.bullet.shape.getGlobalBounds(), tank1.body.getGlobalBounds())) {
            std::cout << "CYAN TANK WIN" << std::endl;
            window.close();
        }

        window.clear();
    
        tank1.bullet.update();
        tank2.bullet.update();
        // tank1.update();
        // tank1.update();

        if (tank1.isAlive) window.draw(tank1.body); 
        if (tank2.isAlive) window.draw(tank2.body);

        window.draw(tank1.bullet.shape);
        window.draw(tank2.bullet.shape);

        window.display();
    }

    return 0;
}
#include <iostream>
#include <cmath>

class Cube {
    private:
        int side;
    
    public:
        Cube() = default;

        Cube(int side) : side(side) {
            std::cout << "[ctor] Cube created" << std::endl << std::endl;
        }

        ~Cube() {
            std::cout << "[dtor] Cube destroyed" << std::endl;
        }
    
        void setSide(int side) {
            this -> side = side;
            // std::cout << "[!] Cube side changed" << std::endl;
        }

        int getArea() {
            return std::pow(side, 2)*6;
        }

        int getVolume() {
            return std::pow(side, 3);
        }

        float getDiagonal() {
            return std::sqrt(3) * side;
        }

        void print() {
            std::cout << "Area: " << getArea() << std::endl;
            std::cout << "Volume: " << getVolume() << std::endl;
            std::cout << "Diagonal: " << getDiagonal() << std::endl;
            std::cout << std::endl;
        }
};


int main() {
    Cube cube(10);
    Cube cube2;

    cube.setSide(100);
    cube2.setSide(10);

    cube.print();
    cube2.print();

    return 0;
}
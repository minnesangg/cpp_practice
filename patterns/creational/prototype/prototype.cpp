#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Shape{
public: 
    virtual ~Shape() = default;
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

class Circle : public Shape{
    int x,y, radius;

public: 
    Circle(int x_, int y_, int r) : x(x_), y(y_), radius(r) {}
    Circle(const Circle& other) : x(other.x), y(other.y), radius(other.radius) {}

    std::unique_ptr<Shape> clone() const override{
        return std::make_unique<Circle>(*this);
    }

    void draw() const override{
        std::cout << "Circle with center (" << x << ", " << y << ") and with radius " << radius << "\n";
    }
};

class Rectangle : public Shape{
    int x, y, width, height;

public: 
    Rectangle(int x_, int y_, int w, int h) : x(x_), y(y_), width(w), height(h) {}
    Rectangle(const Rectangle& other) : x(other.x), y(other.y), width(other.width), height(other.height) {}

    std::unique_ptr<Shape> clone() const override{
        return std::make_unique<Rectangle>(*this);
    }

    void draw() const override{
        std::cout << "Rectangle with cords (" << x << "," << y << ") and with size " << width << "x" << height << "\n";
    }
};

int main(){
    std::vector<std::unique_ptr<Shape>> originals;
    originals.push_back(std::make_unique<Circle>(10, 20, 5));
    originals.push_back(std::make_unique<Rectangle>(0, 0, 100, 50));

    std::vector<std::unique_ptr<Shape>> clones;

    for(const auto& shape : originals){
        clones.push_back(shape->clone());
    }

    for(const auto& clone : clones){
        clone->draw();
    }
}
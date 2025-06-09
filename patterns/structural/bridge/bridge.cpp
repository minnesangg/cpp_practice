#include <iostream>
#include <memory>

class DrawingAPI{
public: 
    virtual void drawCircle(float x, float y, float radius) const = 0;
    virtual ~DrawingAPI() = default;
};

class DrawingAPI_OpenGL : public DrawingAPI{
public: 
    void drawCircle(float x, float y, float radius) const override{
        std::cout << "[OPENGL] Drawing the circle in (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

class DrawingAPI_SVG : public DrawingAPI{
public: 
    void drawCircle(float x, float y, float radius) const override{
        std::cout << "[SVG] <circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << radius << "\" />" << std::endl;
    }
};



class Shape{
protected: 
    std::shared_ptr<DrawingAPI> api;

public: 
    Shape(std::shared_ptr<DrawingAPI> impl) : api(std::move(impl)) {}
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape{
private: 
    float x, y, radius;

public: 
    Circle(float x, float y, float r, std::shared_ptr<DrawingAPI> impl) :
        Shape(std::move(impl)), x(x), y(y), radius(r) {}

    void draw() const override{
        api->drawCircle(x, y, radius);
    }
};


int main(){
    Circle c1(10, 25, 5, std::make_shared<DrawingAPI_OpenGL>());
    Circle c2(50, 50, 10, std::make_shared<DrawingAPI_SVG>());

    c1.draw();
    c2.draw();
}
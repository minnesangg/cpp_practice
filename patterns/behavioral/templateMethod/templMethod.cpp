#include <iostream>

class AbstractClass {
public:
    void templateMethod() {
        step1();
        step2();
        step3();
    }

    virtual ~AbstractClass() = default;

protected:
    virtual void step1() {
        std::cout << "AbstractClass: step1 базовая реализация\n";
    }
    virtual void step2() = 0; 
    virtual void step3() {
        std::cout << "AbstractClass: step3 базовая реализация\n";
    }
};

class ConcreteClassA : public AbstractClass {
protected:
    void step2() override {
        std::cout << "ConcreteClassA: реализация step2\n";
    }
};

class ConcreteClassB : public AbstractClass {
protected:
    void step1() override {
        std::cout << "ConcreteClassB: переопределённый step1\n";
    }
    void step2() override {
        std::cout << "ConcreteClassB: своя реализация step2\n";
    }
    void step3() override {
        std::cout << "ConcreteClassB: переопределённый step3\n";
    }
};

int main() {
    ConcreteClassA a;
    a.templateMethod();

    std::cout << "======\n";

    ConcreteClassB b;
    b.templateMethod();
}
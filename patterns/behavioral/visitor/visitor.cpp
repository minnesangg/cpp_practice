#include <iostream>
#include <vector>
#include <memory>

class Visitor;

class Element {
public:
    virtual ~Element() = default;
    virtual void accept(Visitor& visitor) = 0;
};

class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationA() {
        std::cout << "ConcreteElementA: своя операция\n";
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationB() {
        std::cout << "ConcreteElementB: своя операция\n";
    }
};

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visitConcreteElementA(ConcreteElementA& element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB& element) = 0;
};

void ConcreteElementA::accept(Visitor& visitor) {
    visitor.visitConcreteElementA(*this);
}
void ConcreteElementB::accept(Visitor& visitor) {
    visitor.visitConcreteElementB(*this);
}

class ConcreteVisitor : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA& element) override {
        std::cout << "Посетитель обрабатывает ConcreteElementA\n";
        element.operationA();
    }
    void visitConcreteElementB(ConcreteElementB& element) override {
        std::cout << "Посетитель обрабатывает ConcreteElementB\n";
        element.operationB();
    }
};

int main() {
    std::vector<std::unique_ptr<Element>> elements;
    elements.push_back(std::make_unique<ConcreteElementA>());
    elements.push_back(std::make_unique<ConcreteElementB>());

    ConcreteVisitor visitor;

    for (auto& elem : elements) {
        elem->accept(visitor);
    }

    return 0;
}
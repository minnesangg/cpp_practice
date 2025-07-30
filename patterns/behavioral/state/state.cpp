#include <iostream>
#include <memory>

class State {
public:
    virtual ~State() = default;
    virtual void handle() = 0;
};

class Context {
public:
    Context(std::unique_ptr<State> state) : state_(std::move(state)) {}

    void setState(std::unique_ptr<State> state) {
        state_ = std::move(state);
    }

    void request() {
        state_->handle();
    }

private:
    std::unique_ptr<State> state_;
};

class ConcreteStateA : public State {
public:
    void handle() override {
        std::cout << "Обработка в ConcreteStateA\n";
    }
};

class ConcreteStateB : public State {
public:
    void handle() override {
        std::cout << "Обработка в ConcreteStateB\n";
    }
};

int main() {
    Context context(std::make_unique<ConcreteStateA>());
    context.request(); 

    context.setState(std::make_unique<ConcreteStateB>());
    context.request(); 
}
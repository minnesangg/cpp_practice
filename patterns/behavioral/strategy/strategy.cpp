#include <iostream>
#include <memory>

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void execute() = 0;
};

class Context {
public:
    Context(std::unique_ptr<Strategy> strategy) : strategy_(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<Strategy> strategy) {
        strategy_ = std::move(strategy);
    }

    void doWork() {
        strategy_->execute();
    }

private:
    std::unique_ptr<Strategy> strategy_;
};

class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Выполнение стратегии A\n";
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Выполнение стратегии B\n";
    }
};

int main() {
    Context context(std::make_unique<ConcreteStrategyA>());
    context.doWork();

    context.setStrategy(std::make_unique<ConcreteStrategyB>());
    context.doWork();

    return 0;
}
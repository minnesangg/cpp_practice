#include <iostream>
#include <string>
#include <memory>

class Context {};

class Expression {
public:
    virtual int interpret(Context&) = 0;
    virtual ~Expression() = default;
};

class NumberExpression : public Expression {
public:
    NumberExpression(int number) : number_(number) {}

    int interpret(Context&) override {
        return number_;
    }

private:
    int number_;
};

class AddExpression : public Expression {
public:
    AddExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left_(std::move(left)), right_(std::move(right)) {}

    int interpret(Context& context) override {
        return left_->interpret(context) + right_->interpret(context);
    }

private:
    std::unique_ptr<Expression> left_;
    std::unique_ptr<Expression> right_;
};


int main() {
    Context context;

    auto expression = std::make_unique<AddExpression>(
        std::make_unique<NumberExpression>(5),
        std::make_unique<AddExpression>(
            std::make_unique<NumberExpression>(3),
            std::make_unique<NumberExpression>(2)
        )
    );

    std::cout << "Result: " << expression->interpret(context) << std::endl;
}
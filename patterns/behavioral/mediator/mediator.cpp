#include <iostream>
#include <string>
#include <memory>

class Mediator;

class Colleague {
public:
    Colleague(Mediator* mediator) : mediator_(mediator) {}
    virtual void receive(const std::string& message) = 0;
protected:
    Mediator* mediator_;
};

class Mediator {
public:
    virtual void send(const std::string& message, Colleague* sender) = 0;
    virtual ~Mediator() = default;
};

class ConcreteMediator : public Mediator {
public:
    void setColleagueA(Colleague* col) { colleagueA_ = col; }
    void setColleagueB(Colleague* col) { colleagueB_ = col; }

    void send(const std::string& message, Colleague* sender) override {
        if (sender == colleagueA_) {
            colleagueB_->receive(message);
        } else {
            colleagueA_->receive(message);
        }
    }

private:
    Colleague* colleagueA_;
    Colleague* colleagueB_;
};

class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA(Mediator* mediator) : Colleague(mediator) {}

    void send(const std::string& message) {
        std::cout << "ColleagueA отправляет: " << message << std::endl;
        mediator_->send(message, this);
    }

    void receive(const std::string& message) override {
        std::cout << "ColleagueA получил: " << message << std::endl;
    }
};

class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB(Mediator* mediator) : Colleague(mediator) {}

    void send(const std::string& message) {
        std::cout << "ColleagueB отправляет: " << message << std::endl;
        mediator_->send(message, this);
    }

    void receive(const std::string& message) override {
        std::cout << "ColleagueB получил: " << message << std::endl;
    }
};

int main() {
    ConcreteMediator mediator;

    ConcreteColleagueA colA(&mediator);
    ConcreteColleagueB colB(&mediator);

    mediator.setColleagueA(&colA);
    mediator.setColleagueB(&colB);

    colA.send("Привет от А");
    colB.send("Ответ от Б");

    return 0;
}
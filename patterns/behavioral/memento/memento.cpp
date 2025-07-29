#include <iostream>
#include <string>
#include <vector>

class Memento {
public:
    Memento(const std::string& state) : state_(state) {}
    std::string getState() const { return state_; }

private:
    std::string state_;
};

class Originator {
public:
    void setState(const std::string& state) {
        state_ = state;
        std::cout << "Установлено состояние: " << state_ << "\n";
    }

    std::string getState() const {
        return state_;
    }

    Memento save() {
        return Memento(state_);
    }

    void restore(const Memento& memento) {
        state_ = memento.getState();
        std::cout << "Восстановлено состояние: " << state_ << "\n";
    }

private:
    std::string state_;
};

class Caretaker {
public:
    void addMemento(const Memento& memento) {
        history_.push_back(memento);
    }

    Memento getMemento(int index) {
        return history_.at(index);
    }

private:
    std::vector<Memento> history_;
};

int main() {
    Originator originator;
    Caretaker caretaker;

    originator.setState("Состояние 1");
    caretaker.addMemento(originator.save());

    originator.setState("Состояние 2");
    caretaker.addMemento(originator.save());

    originator.setState("Состояние 3");

    originator.restore(caretaker.getMemento(0));

    return 0;
}
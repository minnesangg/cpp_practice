#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(int state) = 0;
};

class Subject {
public:
    void attach(Observer* observer) {
        observers_.push_back(observer);
    }

    void detach(Observer* observer) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }

    void notify() {
        for (auto observer : observers_) {
            observer->update(state_);
        }
    }

    void setState(int state) {
        state_ = state;
        notify();
    }

    int getState() const { return state_; }

private:
    std::vector<Observer*> observers_;
    int state_ = 0;
};

class ConcreteObserverA : public Observer {
public:
    void update(int state) override {
        std::cout << "ConcreteObserverA получил обновление: " << state << "\n";
    }
};

class ConcreteObserverB : public Observer {
public:
    void update(int state) override {
        std::cout << "ConcreteObserverB получил обновление: " << state << "\n";
    }
};

int main() {
    Subject subject;

    ConcreteObserverA observerA;
    ConcreteObserverB observerB;

    subject.attach(&observerA);
    subject.attach(&observerB);

    subject.setState(10);
    subject.setState(20);

    subject.detach(&observerA);

    subject.setState(30);

    return 0;
}
#include <iostream>
#include <vector>
#include <memory>

class Iterator {
public:
    virtual int current() = 0;
    virtual bool hasNext() = 0;
    virtual void next() = 0;
    virtual ~Iterator() = default;
};

class Aggregate {
public:
    virtual std::unique_ptr<Iterator> createIterator() = 0;
    virtual ~Aggregate() = default;
};

class NumberCollection : public Aggregate {
public:
    void add(int number) { numbers.push_back(number); }

    class NumberIterator : public Iterator {
    public:
        NumberIterator(NumberCollection* collection)
            : collection_(collection), index_(0) {}

        int current() override {
            return collection_->numbers[index_];
        }

        bool hasNext() override {
            return index_ < collection_->numbers.size();
        }

        void next() override {
            ++index_;
        }

    private:
        NumberCollection* collection_;
        size_t index_;
    };

    std::unique_ptr<Iterator> createIterator() override {
        return std::make_unique<NumberIterator>(this);
    }

private:
    std::vector<int> numbers;
};

int main() {
    NumberCollection collection;
    collection.add(10);
    collection.add(20);
    collection.add(30);

    auto it = collection.createIterator();

    while (it->hasNext()) {
        std::cout << it->current() << " ";
        it->next();
    }
    std::cout << "\n";

    return 0;
}
#include <iostream>
#include <string>
#include <memory>

class Text{
public: 
    virtual std::string render() const = 0;
    virtual ~Text() = default;
};

class PlainText : public Text{
    std::string content;

public: 
    explicit PlainText(std::string str) : content(std::move(str)) {}

    std::string render() const override{
        return content;
    }
};

class TextDecorator : public Text{
protected: 
    std::shared_ptr<Text> wrapee;

public: 
    explicit TextDecorator(std::shared_ptr<Text> component) : wrapee(std::move(component)) {}

};

class BoldText : public TextDecorator{
public: 
    using TextDecorator::TextDecorator;

    std::string render() const override{
        return "<b>" + wrapee->render() + "<b>";
    }
};

class ItalicText : public TextDecorator{
public: 
    using TextDecorator::TextDecorator;

    std::string render() const override{
        return "<i>"+ wrapee->render() + "<i>";
    }
};

int main(){
    std::shared_ptr<Text> text = std::make_shared<PlainText>("Hello, world!");

    text = std::make_shared<BoldText>(text);
    text = std::make_shared<ItalicText>(text);

    std::cout << text->render() << std::endl;
}
#include <iostream>
#include <unordered_map>
#include <memory>

class CharacterStyle {
public:
    CharacterStyle(const std::string& font, int size, const std::string& color)
        : font_(font), size_(size), color_(color) {}

    void display(char c, int x, int y) const {
        std::cout << "Символ '" << c << "' на (" << x << ", " << y << ") "
                  << "со стилем: [" << font_ << ", " << size_ << "pt, " << color_ << "]\n";
    }

private:
    std::string font_;
    int size_;
    std::string color_;
};

class StyleFactory {
public:
    std::shared_ptr<CharacterStyle> getStyle(const std::string& font, int size, const std::string& color) {
        std::string key = font + std::to_string(size) + color;
        if (styles.find(key) == styles.end()) {
            styles[key] = std::make_shared<CharacterStyle>(font, size, color);
        }
        return styles[key];
    }

private:
    std::unordered_map<std::string, std::shared_ptr<CharacterStyle>> styles;
};

class Character {
public:
    Character(char symbol, int x, int y, std::shared_ptr<CharacterStyle> style)
        : symbol_(symbol), x_(x), y_(y), style_(style) {}

    void render() const {
        style_->display(symbol_, x_, y_);
    }

private:
    char symbol_;
    int x_, y_;
    std::shared_ptr<CharacterStyle> style_;
};

int main() {
    StyleFactory factory;

    auto style1 = factory.getStyle("Arial", 12, "Black");
    auto style2 = factory.getStyle("Arial", 12, "Black"); 

    Character a('A', 10, 20, style1);
    Character b('B', 15, 20, style2); 

    a.render();
    b.render();
}
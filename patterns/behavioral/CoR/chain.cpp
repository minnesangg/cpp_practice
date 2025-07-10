#include <iostream>
#include <memory>
#include <string>

class Handler {
public:
    virtual Handler* setNext(Handler* next) {
        next_ = next;
        return next_;
    }

    virtual bool handle(const std::string& request) {
        if (next_) return next_->handle(request);
        return true; 
    }

    virtual ~Handler() = default;

protected:
    Handler* next_ = nullptr;
};

class LoginHandler : public Handler {
public:
    bool handle(const std::string& request) override {
        std::cout << "Проверка логина...\n";
        if (request != "user") {
            std::cout << "Неверный логин!\n";
            return false;
        }
        return Handler::handle(request);
    }
};

class PasswordHandler : public Handler {
public:
    bool handle(const std::string& request) override {
        std::cout << "Проверка пароля...\n";
        if (request == "user") {
            std::cout << "Пароль верный.\n";
            return Handler::handle(request);
        }
        return false;
    }
};

class AdminHandler : public Handler {
public:
    bool handle(const std::string& request) override {
        std::cout << "Проверка прав администратора...\n";
        if (request == "user") {
            std::cout << "Права подтверждены.\n";
            return true;
        }
        return false;
    }
};

int main() {
    LoginHandler login;
    PasswordHandler password;
    AdminHandler admin;

    login.setNext(&password)->setNext(&admin);

    std::string request = "user";

    if (login.handle(request)) {
        std::cout << "Доступ разрешён.\n";
    } else {
        std::cout << "Доступ запрещён.\n";
    }

    return 0;
}
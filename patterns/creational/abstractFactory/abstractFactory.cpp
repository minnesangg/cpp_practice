#include <iostream>
#include <memory>

class Button{
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};

class CheckBox{
public:
    virtual void render() = 0;
    virtual ~CheckBox() = default;
};

class WindowsButton : public Button{
public:
    void render() override{
        std::cout << "[WIN] Button" << std::endl;
    }
};

class WindowsCheckBox : public CheckBox{
public: 
    void render() override{
        std::cout << "[WIN] CheckBox" << std::endl;
    }
};


class LinuxButton : public Button{
public: 
    void render() override{
        std::cout << "[LINUX] Button" << std::endl;
    }
};

class LinuxCheckBox : public CheckBox{
public:
    void render() override{
        std::cout << "[LINUX] CheckBox" << std::endl;
    }
};


class GUIFactory{
public:
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<CheckBox> createCheckBox() = 0;
    virtual ~GUIFactory() = default;
};

class WindowsFactory : public GUIFactory{
public:
    std::unique_ptr<Button> createButton() override{
        return std::make_unique<WindowsButton>();
    }

    std::unique_ptr<CheckBox> createCheckBox() override{
        return std::make_unique<WindowsCheckBox>();
    }
};

class LinuxFactory : public GUIFactory{
public:
    std::unique_ptr<Button> createButton() override{
        return std::make_unique<LinuxButton>();
    }

    std::unique_ptr<CheckBox> createCheckBox() override{
        return std::make_unique<LinuxCheckBox>();
    }
};


void renderUI(GUIFactory& factory){
    auto button = factory.createButton();
    auto checkBox = factory.createCheckBox();

    button->render();
    checkBox->render();
}

int main(){
    WindowsFactory winFactory;
    LinuxFactory linuxFactory;

    std::cout << "Rendering UI for WIN" << std::endl;
    renderUI(winFactory);

    std::cout << "Rendering UI for Linux" << std::endl;
    renderUI(linuxFactory);
}
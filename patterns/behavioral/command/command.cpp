#include <iostream>
#include <memory>
#include <stack>

class Light {
public:
    void on()  { std::cout << "Свет включён\n"; }
    void off() { std::cout << "Свет выключен\n"; }
};


class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};


class LightOnCommand : public Command {
public:
    LightOnCommand(Light* light) : light_(light) {}

    void execute() override { light_->on(); }
    void undo() override    { light_->off(); }

private:
    Light* light_;
};

class LightOffCommand : public Command {
public:
    LightOffCommand(Light* light) : light_(light) {}

    void execute() override { light_->off(); }
    void undo() override    { light_->on(); }

private:
    Light* light_;
};


class RemoteControl {
public:
    void submit(Command* cmd) {
        cmd->execute();
        history.push(cmd);
    }

    void undoLast() {
        if (!history.empty()) {
            Command* cmd = history.top();
            cmd->undo();
            history.pop();
        }
    }

private:
    std::stack<Command*> history;
};

int main() {
    Light light;

    LightOnCommand onCmd(&light);
    LightOffCommand offCmd(&light);

    RemoteControl remote;

    remote.submit(&onCmd);   
    remote.submit(&offCmd);  
    remote.undoLast();      

    return 0;
}
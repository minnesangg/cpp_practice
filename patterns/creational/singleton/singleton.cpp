#include <iostream>
#include <string>

class Singleton {
private:
    Singleton() = default;
    ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    size_t logCount = 0;

public:
    enum class LogLevel { INFO, WARNING, ERROR };

    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void log(const std::string& msg, LogLevel level = LogLevel::INFO) {
        ++logCount;

        switch(level) {
            case LogLevel::INFO:
                std::cout << "#" << logCount << " [INFO] " << msg << std::endl;
                break;
            case LogLevel::WARNING:
                std::cout << "#" << logCount << " [WARNING] " << msg << std::endl;
                break;
            case LogLevel::ERROR:
                std::cout << "#" << logCount << " [ERROR] " << msg << std::endl;
                break;
            default:
                std::cout << "#" << logCount << " [UNKNOWN] " << msg << std::endl;
                break;
        }
    }
};

int main() {
    Singleton::getInstance().log("program started", Singleton::LogLevel::INFO);
    Singleton::getInstance().log("testing of logging", Singleton::LogLevel::WARNING);
    Singleton::getInstance().log("testing of error", Singleton::LogLevel::ERROR);
}

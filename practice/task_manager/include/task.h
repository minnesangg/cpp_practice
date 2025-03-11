#ifndef TASK_H
#define TASK_H

#include <string>
#include "json.hpp"

class Task {
public:
    std::string title;
    std::string description;
    bool done;

    enum class Priority {
        Low,
        Mid,
        High
    };

    Priority priority;

    Task();

    Task(std::string title, std::string description, bool done = false, Priority priority = Priority::Low);

    nlohmann::json to_json() const;
    static Task from_json(const nlohmann::json& j);
};

#endif

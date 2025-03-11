#include "task.h"

Task::Task() : title(""), description(""), done(false), priority(Priority::Low) {}

Task::Task(std::string title, std::string description, bool done, Priority priority) :
    title(std::move(title)), description(std::move(description)), done(done), priority(priority) {}

nlohmann::json Task::to_json() const {
    std::string p;
    switch (priority) {
        case Priority::Low: p = "low"; break;
        case Priority::Mid: p = "middle"; break;
        case Priority::High: p = "high"; break;
    }
    return {{"title", title}, {"description", description}, {"is done", done}, {"priority", p}};
}

Task Task::from_json(const nlohmann::json& j) {
    Task task;
    task.title = j.at("title").get<std::string>();
    task.description = j.at("description").get<std::string>();

    if (j.contains("is_done") && j.at("is_done").is_boolean()) {
        task.done = j.at("is_done").get<bool>();  
    } else {
        task.done = false; 
    }

    if (j.contains("priority")) {
        std::string priority_str = j.at("priority").get<std::string>();
        if (priority_str == "low") {
            task.priority = Task::Priority::Low;
        } else if (priority_str == "middle") {
            task.priority = Task::Priority::Mid;
        } else if (priority_str == "high") {
            task.priority = Task::Priority::High;
        }
    }

    return task;
}



#include "taskManager.h"

void TaskManager::add_task(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::mark_as_done(size_t index) {
    if (index < tasks.get_size()) {
        tasks[index].done = true; 
        save_to_file();  
    }
}

void TaskManager::remove_task(size_t index) {
    if (index < tasks.get_size()) {
        tasks.erase(index);
    }
}

void TaskManager::show_tasks() const {
    for (size_t i = 0; i < tasks.get_size(); i++) {
        std::string p;
        switch (tasks[i].priority) {
            case Task::Priority::Low:
                p = "low";
                break;
            case Task::Priority::Mid:
                p = "middle";
                break;
            case Task::Priority::High:
                p = "high";
                break;
        }
        std::cout << i + 1 << ". [" << (tasks[i].done ? "Yes" : "No") << "] "
                  << tasks[i].title << " (" << p << ")\n"
                  << "    " << tasks[i].description << "\n";
    }
}

void TaskManager::save_to_file() {
    std::ofstream file(FILENAME);
    nlohmann::json j;
    for (const auto& task : tasks) {
        j.push_back(task.to_json());
    }
    file << j.dump(4);
}

void TaskManager::load_from_file() {
    std::ifstream file("tasks.json");
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    nlohmann::json j;
    file >> j;

    for (const auto& task_json : j) {
        std::string title = task_json.at("title").get<std::string>();
        std::string description = task_json.at("description").get<std::string>();
        bool is_done = task_json.at("is done").get<bool>();  
        std::string priority_str = task_json.at("priority").get<std::string>();

        std::cout << "Loaded: " << title << ", " << description << ", done: " << is_done << ", priority: " << priority_str << std::endl;

        Task task;
        task.title = title;
        task.description = description;
        task.done = is_done;

        if (priority_str == "low") {
            task.priority = Task::Priority::Low;
        } else if (priority_str == "middle") {
            task.priority = Task::Priority::Mid;
        } else if (priority_str == "high") {
            task.priority = Task::Priority::High;
        }

        tasks.push_back(task);
    }
}

#include "taskManager.h"

void show_menu() {
    std::cout << "\n1. Add task\n2. Mark as done\n3. Delete task\n4. Show all tasks\n5. Exit\n";
}

int main() {
    TaskManager manager;
    manager.load_from_file();

    while (true) {
        show_menu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string title, description, priority_str;
                std::cout << "Title: ";
                std::getline(std::cin, title);
                std::cout << "Description: ";
                std::getline(std::cin, description);
                std::cout << "Priority (low, middle, high): ";
                std::getline(std::cin, priority_str);

                Task::Priority priority;
                if (priority_str == "low") {
                    priority = Task::Priority::Low;
                } else if (priority_str == "middle") {
                    priority = Task::Priority::Mid;
                } else if (priority_str == "high") {
                    priority = Task::Priority::High;
                }

                Task task(title, description, false, priority);
                manager.add_task(task);
                break;
            }
            case 2: {
                size_t index;
                std::cout << "Task number: ";
                std::cin >> index;
                manager.mark_as_done(index - 1);
                break;
            }
            case 3: {
                size_t index;
                std::cout << "Task number: ";
                std::cin >> index;
                manager.remove_task(index - 1);
                break;
            }
            case 4:
                manager.show_tasks();
                break;
            case 5:
                manager.save_to_file();
                return 0;
        }
    }

    return 0;
}

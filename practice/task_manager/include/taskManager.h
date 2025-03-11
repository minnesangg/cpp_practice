#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "task.h"
#include "mnsng_vector.h"
#include <fstream>
#include <iostream>

class TaskManager {
private:
    minnesang::Vector<Task> tasks;
    const std::string FILENAME = "tasks.json";

public:
    void add_task(const Task& task);
    void mark_as_done(size_t index);
    void remove_task(size_t index);
    void show_tasks() const;

    void save_to_file();
    void load_from_file();
};

#endif

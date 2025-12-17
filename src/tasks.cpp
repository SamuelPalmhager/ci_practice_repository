#include "tasks.h"

int TaskManager::addTask(const string& description) {
    Task newTask;
    newTask.id = nextId++;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    return newTask.id;
}

bool TaskManager::completeTask(int id) {
    for (auto& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            return true;
        }
    }
    return false;
}

bool TaskManager::removeTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            return true;
        }
    }
    return false;
}

string TaskManager::getTaskString(int id) {

    string tasksStr = "";

    for (const auto& task : tasks) {
        if (task.id == id) {
            tasksStr += "ID: " + to_string(task.id) + ", Description: " + task.description + ", Completed: " + (task.completed ? "Yes" : "No") + "\n";
        }
    }
    return tasksStr;
}

string TaskManager::getTasksString() const {
    string tasksStr = "";
    for (const auto& task : tasks) {
        tasksStr += "ID: " + to_string(task.id) + ", Description: " + task.description + ", Completed: " + (task.completed ? "Yes" : "No") + "\n";
    }
    return tasksStr;
}
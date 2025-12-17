#ifndef _TASKS_H_
#define _TASKS_H_

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Task {
    int id;
    string description;
    bool completed;
};

class TaskManager {
    private:
        vector<Task> tasks;
        int nextId = 1;
    public:
        TaskManager() = default;
        
        int addTask(const string& description);
        bool completeTask(int id);
        bool removeTask(int id);
        string getTaskString(int id);
        string getTasksString() const;
};

#endif /* _TASKS_H_ */
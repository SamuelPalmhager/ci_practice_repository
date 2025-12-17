#include "httplib.h"
#include "tasks.h"
#include <iostream>

int main() {

    /** 
     * GET /tasks               --> Lists all tasks
     * GET /tasks/{id}          --> Returns a specific task based on id
     * POST /tasks              --> Adds a new task to the list in JSON format
     * POST /tasks/{id}         --> Completes a specific task based on id
     * DELETE /tasks/{id}       --> Delete a task from the list based on provided id
     * 
     * Example usage:
     * 
     * curl http://localhost:8080/tasks --> lists all our tasks (GET)
     * curl -X POST -d 'Study' http://localhost:8080/tasks --> Adds the "study" task to list of tasks (POST)
     * curl -X DELETE http://localhost:8080/tasks/1 --> Deletes the task with an id of 1 from list of tasks (DELETE)
     */

    httplib::Server server;
    TaskManager manager = TaskManager();

    server.Get("/tasks", [&manager](const httplib::Request& req, httplib::Response& res){
        std::cout << "Received GET request for /tasks\n" << std::endl;

        res.set_content(manager.getTasksString(), "text/plain");

    });

    server.Post("/tasks", [&manager](const httplib::Request& req, httplib::Response& res){
        std::cout << "Received POST request for /tasks\n" << std::endl;
        
        if (manager.addTask(req.body)){
            res.set_content("Task added", "text/plain");
        } else {
            res.set_content("Error adding task", "text/plain");
        }
            
    });

    server.Post("/tasks/:id", [&manager](const httplib::Request& req, httplib::Response& res){
        std::cout << "Received POST request for /tasks/\n" << std::endl;

        int id = stoi(req.path_params.at("id"));
        if (manager.completeTask(id)) {
            res.set_content("Task completed", "text/plain");
        } else {    
            res.set_content("Error completing task", "text/plain");
        }
        
    });

    server.Delete("/tasks/:id", [&manager](const httplib::Request& req, httplib::Response& res){
        std::cout << "Received DELETE request for /tasks/\n" << std::endl;

        int id = stoi(req.path_params.at("id"));
        if (manager.removeTask(id)) {
            res.set_content("Task deleted", "text/plain");
        } else {    
            res.set_content("Error deleting task", "text/plain");
        }
        
    });

    server.Get("/tasks/:id", [&manager](const httplib::Request& req, httplib::Response& res){
        std::cout << "Received PUT request for /tasks/\n" << std::endl;

        int id = stoi(req.path_params.at("id"));

        string task = manager.getTaskString(id);

        if (!task.empty()){
            res.set_content("Task found", "text/plain");
            string response = "Task found ";
            response += task;
            res.set_content(response, "text/plain");
        } else {
            res.set_content("Error finding task", "text/plain");
        }

    });
    
    std::cout << "Server running on http://localhost:8080\n" << std::endl;

    server.listen("0.0.0.0", 8080);

    return 0;
}
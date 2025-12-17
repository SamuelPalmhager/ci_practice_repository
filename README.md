ci_practice_project

Objective for project:

Simple C++ REST API server for a To-Do list

Project structure:

todo-server/
├── src/
│   ├── main.cpp
│   ├── server.cpp
│   ├── server.h
│   ├── tasks.cpp
│   └── tasks.h
├── tests/
│   └── test_tasks.cpp
├── include/
│   └── httplib.h
├── Makefile
├── README.md
└── .github/
    └── workflows/
        └── ci.yml

CI Pipeline Goals:

Build stage:
    - make
    - checks warnings
    - fails on error

Test stage:
    - make test
    - runs GoogleTest

Lint stage:
    - clang-format or cppcheck

Artifact:
    - Upload compiled server binary

Suggested frameworks to use:
    - HTTP Library: cpp-httplib (external repo)
    - Header-only -> no external linking        headaches. 

PR 1 (in progress) - basic server skeleton
    - Initial structure of project
    - main.cpp:
        - Using httpcpp-library spin up easy listening server on port 8080
        - single GET endpoint

        - Compile using: 
        - make all
        - Execute binary -> server listens on port 8080, open http://localhost:8080/health browser to see response 
        - Or use curl: 
        - curl http://localhost:8080/health

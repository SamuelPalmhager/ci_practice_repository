all: output/server

output/server: src/main.cpp src/tasks.cpp | output 
	g++ -I include -I src src/main.cpp src/tasks.cpp -o output/server
	
output:
	mkdir -p output
	
clean: 
	rm -r output
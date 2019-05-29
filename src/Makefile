output: main.o pathfinder.o
	g++ -g main.o pathfinder.o -o pathfinder

main.o: main.cpp
	g++ -g -std=gnu++11 -c main.cpp

pathfinder.o: pathfinder.cpp
	g++ -g -std=gnu++11 -c pathfinder.cpp

clean:
	rm *.o pathfinder	

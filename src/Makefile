output: main.o pathfinder.o
	g++ -gdb main.o pathfinder.o -o pathfinder

main.o: main.cpp
	g++ -std=gnu++11 -c main.cpp

pathfinder.o: pathfinder.cpp
	g++ -std=gnu++11 -c pathfinder.cpp

clean:
	rm *.o pathfinder	

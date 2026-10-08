all: robot

robot: RoboticArm.o main.o
	g++ RoboticArm.o main.o -o robot

RoboticArm.o: RoboticArm.cpp RoboticArm.h
	g++ -c RoboticArm.cpp

main.o: main.cpp RoboticArm.h
	g++ -c main.cpp

test: robot
	./robot

clean:
	rm -f *.o robot

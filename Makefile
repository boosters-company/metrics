CC=g++
FLAGS=-std=c++0x -c -O3

all: rmsle f1


rmsle: rmsle.o utils.o
	$(CC) rmsle.o utils.o -o rmsle

rmsle.o: rmsle.cpp
	$(CC) $(FLAGS) rmsle.cpp
	
utils.o: utils.cpp
	$(CC) $(FLAGS) utils.cpp
	
	
f1: f1_score.o utils.o
	$(CC) f1_score.o utils.o -o f1
	
f1_score.o: f1_score.cpp
	$(CC) $(FLAGS) f1_score.cpp
	
clean:
	rm -rf *.o rmsle
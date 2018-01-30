CC=g++
FLAGS=-std=c++0x -c -O3

all: rmsle f1 accuracy log_loss hit hit_2


log_loss: log_loss.o utils.o
	$(CC) log_loss.o utils.o -o log_loss
	
log_loss.o: log_loss.cpp
	$(CC) $(FLAGS) log_loss.cpp

hit: hit.o utils.o
	$(CC) hit.o utils.o -o hit

hit.o: hit.cpp
	$(CC) $(FLAGS) hit.cpp

hit_2: hit_2.o utils.o
	$(CC) hit_2.o utils.o -o hit_2

hit_2.o: hit_2.cpp
	$(CC) $(FLAGS) hit_2.cpp

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
	
	
accuracy: accuracy.o utils.o
	$(CC) accuracy.o utils.o -o accuracy
	
accuracy.o: accuracy.cpp
	$(CC) $(FLAGS) accuracy.cpp
	
clean:
	rm -rf *.o rmsle
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void read_data_csv(string path, unordered_map<int, double> *data);
int* read_indexes(string path);


extern int SIZE;

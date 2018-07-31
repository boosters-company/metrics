#include <iostream>
#include <unordered_map>
#include <math.h>
#include <sstream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct coord {
    double lat, lon;
};

void read_data_csv(string path, unordered_map<int, double> *data);
void read_data_coord(string path, unordered_map<string, coord> *data);
void read_data_coord_2(string path, unordered_map<string, coord> *data1, unordered_map<string, coord> *data2);
int* read_indexes(string path);
string* read_indexes_coords(string path);
void read_mapping(string path, unordered_map<string, double> *data);



extern int SIZE;

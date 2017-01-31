
#include "utils.h"
extern int SIZE;
void read_data_csv(string path, unordered_map<int, double> *data) {
    
    ifstream in;
    in.open(path, ifstream::in);
    
    string line, cell;
    in >> line;
    int ind;
    double val;
    
    int state = 0;
    while(!in.eof()) {
        in >> line;
        
        stringstream line_stream(line);
        
        while(getline(line_stream, cell, ',')) {
            
            if(cell.empty()) {
                throw "Empty cell";
            }
            if(state % 2 == 0) {
                ind = stoi(cell);
            } else {
                val = stod(cell);
                (*data)[ind] = val;
            }
            
            state++;
            
        }
    }
    
    in.close();
}

int* read_indexes(string path) {
    ifstream in;
    in.open(path, ifstream::in);
    int size, i = 0;
    int *ind;
    in >> size;
    ind = new int[size];
    
    for(int i = 0; i < size; i++) {
        in >> ind[i];
    }
    
    
    in.close();
    
    SIZE = size;
    return ind;
}
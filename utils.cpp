
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
            
            if(state % 2 == 0) {
                try {
                ind = stoi(cell);
                } catch(const invalid_argument& ia) {
                    
                    cout << "Invalid argumaent: " << cell << endl ;
                    throw "Invalid argumaent";
                    
                } catch(const out_of_range& oor) {
                    
                    cout << "Out of range: " << cell << endl;
                    throw "Out of range";
                    
                }
            } else {
                try {
                val = stod(cell);
                } catch(const invalid_argument& ia) {
                    
                    cout << "Invalid argumaent: " << cell << endl ;
                    throw "Invalid argumaent";
                    
                } catch(const out_of_range& oor) {
                    
                    cout << "Out of range: " << cell << endl;
                    throw "Invalid argumaent";
                    
                }
                (*data)[ind] = val;
            }
            
            state++;
            
        }
        
        if(cell.empty() && !line_stream) {
            
                cout<<"Empty cell"<<endl;
                throw "Empty cell";
                
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
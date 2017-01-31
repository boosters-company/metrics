
#include "utils.h"


int SIZE;

void read_data_csv(string path, unordered_map<int, double> *data);
int* read_indexes(string path);
double rmsle(unordered_map<int, double> *y_true, unordered_map<int, double> *y_pred, int *ind, int size);

int main(int argc, char* argv[]) {
    
    unordered_map<int, double> table1, table2;
    read_data_csv(string(argv[1]), &table1);
    read_data_csv(string(argv[2]), &table2);
    cout << "OK: read csv" << endl;
    int *ind;
    ind = read_indexes(string(argv[3]));
    cout << "OK: read indexes" << endl;
    cout << rmsle(&table1, &table2, ind, SIZE);
    
    delete ind, table1, table2;
    return 0;
}


double rmsle(unordered_map<int, double> *y_true, unordered_map<int, double> *y_pred, int *ind, int size) {
    double tmp, sum = 0;
    int idx;
    for(int i = 0; i < size; i++) {
        idx = ind[i];
        tmp = log((*y_true)[idx] + 1) - log((*y_pred)[idx] + 1);
        tmp *= tmp;
        sum += tmp / size;
    }
    
    return sqrt(sum);
}


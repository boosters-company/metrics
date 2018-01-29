#include "utils.h"
#include "math.h"
#define R 0.02
int SIZE;

double hit(unordered_map<string, coord> *y_true, unordered_map<string, coord> *y_pred, string *ind, int size);

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio (false);

    string *ind;
    unordered_map<string, coord> table_1_1, table_1_2, table_2_1, table_2_2;

    read_data_coord_2(string(argv[2]), &table_1_1, &table_1_2);
    read_data_coord_2(string(argv[2]), &table_2_1, &table_2_2);
    ind = read_indexes_coords(string(argv[3]));

    double score_1 = hit(&table_1_1, &table_1_2, ind, SIZE);
    double score_2 = hit(&table_2_1, &table_2_2, ind, SIZE);

    cout << "ok:" << ((score_1 + score_2)/2.0) << endl;


    return 0;
}

double dist_eu(coord a, coord b) {
    double dist;
    dist = sqrt((a.lat - b.lat)*(a.lat - b.lat) + (a.lon - b.lon)*(a.lon - b.lon));
    return dist;
}

double hit(unordered_map<string, coord> *y_true, unordered_map<string, coord> *y_pred, string *ind, int size) {

    double acc = 0;
    double dist = 0;
    string idx;

    for(int i = 0; i < size; i++) {

        idx = ind[i];
        if((*y_pred).count(idx)) {
           dist = dist_eu((*y_true)[idx], (*y_pred)[idx]);
           acc += (dist < R)*1.0/size;
//            cout << acc << " " << dist << endl;
        } else {
                cout << "error:Index does not exist: " << idx << endl;
                throw  "error:Index does not exist";
        }
    }

    return acc;
}


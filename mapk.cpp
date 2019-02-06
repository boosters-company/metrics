#include "json/json.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;


double avg_precision_at_k(nlohmann::json y_pred, nlohmann::json y_true, int k) {
    double count = 0;
    double avp = 0;
    vector<int> v = y_true.get<vector<int>>();
    set<int> s(v.begin(), v.end());
    vector<int> v2 = y_pred.get<vector<int>>();
    if(y_pred.size() < k) k = y_pred.size();
    for(int i = 0; i < k; i++) {

        count += s.count(v2[i]);
        if(s.count(v2[i]) != 0) {
            avp += count/(i + 1);
        }
    }
    if(y_true.size() < k) k = y_true.size();
    if(avp/k == 1) {
        cout << count << " " << k << " " << avp <<  " " << avp/k <<endl;
        cout << y_pred << endl;
        cout << y_true << endl;
    }
    return avp/k;
}

double mapk(nlohmann::json y_pred, nlohmann::json y_true) {
    double m;
    double N = y_true.size();
    double mm = 0;
    double pr;
    for (auto& i : y_true.items()) {
        pr = avg_precision_at_k(y_pred[i.key()], i.value(), 20);
        if(pr > mm) mm = pr;
        m += pr/N;
    }
    return m;
}

int main(int argc, char* argv[]) {

    ifstream in1, in2;
    in1.open("sample_answer.json", ifstream::in);
    in2.open("public_test_dict.json", ifstream::in);
    nlohmann::json j1, j2;
    in1 >> j1;
    cout << "Loaded first file." << endl;

    in2 >> j2;
    cout << "Loaded second file." << endl;

    cout << mapk(j1, j2) << endl;

    return 0;
}
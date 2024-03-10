#include "TSP_Parcer.h"

vector<pair<double, double>>TSP_Parser::read(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()){
        cerr<<"Error opening file"<<endl;
        return{};
    }
    int n;
    file>>n;
    vector<pair<double, double>> data;
    double x,y;
    while (file>>x>>y){
        data.push_back({x,y});
    }
    file.close();
    return data;
}

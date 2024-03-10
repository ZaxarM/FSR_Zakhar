#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solver {
public:
    Solver(const vector<pair<double,double>>& p);
    void solve();

private:
    vector<pair<double,double>> p;
    double distance(const pair<double,double>& a,const pair<double,double>& b);
    double calculateway(const vector<int>& way);
};

#endif // SOLVER_H

#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solver {
private:
    const vector<vector<int>>& adj_List;
    vector<int> result;

public:
    Solver(const vector<vector<int>>& adjacencyList);
    void colorGraph(int n);
    void printColors(int n);
};

#endif // SOLVER_H

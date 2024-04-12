#include "Solver.h"
#include <iostream>
using namespace std;

Solver::Solver(const vector<vector<int>>& adjList) : adj_List(adjList), result(adjList.size(), 0) {}

void Solver::colorGraph(int n) {
    int u;
    for (u=0;u<n;u++) {
        bool usedcolors[n+1]={false};
        for (int i : adj_List[u])
            if (result[i]!=0&&result[i]<=n)
                usedcolors[result[i]]=true;
        int j=1;
        for ( ; j<=n;j++) {
            if (!usedcolors[j])
                break;
        }
        result[u]=j;
    }
}
void Solver::printColors(int n) {
    int v;
    for (v=0;v < n; v++) {
        cout<<"The color of vertex "<<v<<" is "<<result[v]<<endl;
    }
}

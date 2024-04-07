#include "Solver.h"
using namespace std;
void Solver::var(vector<std::pair<int,vector<int>>>& p, int s) {
    int i,j;
    int n=p.size();
    for (i=0;i<n;i++) {
        p[i].second.resize(s);
        for (j=0;j<s;j++)
            p[i].second[j]=rand()%2==1;
    }
}

pair<int,vector<int>> Solver::genetic_algorithm(const std::vector<Thing>& t, double max_weight, int pop_size, int gen_num) {
    srand(time(nullptr));
    int i,j,k;
    pair<int, vector<int>> best_sol;
    int best_val=0;
    for (i=0;i<gen_num;i++) {
        vector<pair<int, vector<int>>> p(pop_size);
        var(p, t.size());
        for (j=0;j<pop_size;j++) {
            double v=0,w=0;
            for (k=0;k<t.size();k++) {
                if (p[j].second[k]) {
                    v+=t[k].v;
                    w+=t[k].w;
                }
            }
            if ((v>best_val)&&(w<=max_weight)) {
                best_sol=p[j];
                best_val=v;
            }
        }
    }
    int remain_weight=max_weight;
    int total_val= 0;
    for (i=0;i<t.size();i++)
        if (best_sol.second[i]){
            remain_weight-=t[i].w;
            total_val+=t[i].v;
        }
    cout <<total_val<<" "<<remain_weight<<endl;
    for (bool t : best_sol.second)
        cout<<t<<" ";
    cout<<endl;
    return best_sol;
}

#include "solver.h"

Solver::Solver(const vector<pair<double,double>>& p):p(p){}

void Solver::solve() {
    vector<int> v(p.size());
    for (int i=0;i<p.size(); i++)
        v[i]=i;
    double min_dist=calculateway(v);
    vector<int> min_way = v;
    int improved=1;
    while(improved==1){
        improved=0;
        for (size_t i=0;i<p.size();i++)
            for (size_t j=i+1;j<p.size();j++) {
                swap(v[i], v[j]);
                double dist=calculateway(v);
                if (dist<min_dist) {
                    min_dist=dist;
                    min_way=v;
                    improved=1;
                } else
                    swap(v[i],v[j]);
            }
    }

    cout<<"Optimal way:"<<endl;
    for (int i=0;i<p.size();i++)
        cout<<min_way[i]+1<<" --> ";
    cout<<min_way[0]+1<<endl;
    cout<<"Optimal distance: "<<min_dist<<endl;
}

double Solver::distance(const pair<double, double>& a, const pair<double,double>& b) {
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

double Solver::calculateway(const vector<int>& way) {
    double dist=0;
    for (size_t i=0;i<way.size()-1;i++) {
        dist+=distance(p[way[i]],p[way[i+1]]);
    }
    dist+=distance(p[way[way.size()-1]],p[way[0]]);
    return dist;
}

#include "Solver.h"
#include <algorithm>
using namespace std;
double Solver::knapsack_var2(vector<Item>& items, int max_weight, int n) {
    vector<Item> sortedItems = items;
    int i, j;
    sort(sortedItems.begin(), sortedItems.end(), compareItems);
    int max_value=0;
    vector<int> best_taken(n, 0);
    backtrack(0,n,items,sortedItems,max_weight,0,0,0,max_value,best_taken);
    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (items[j].weight==sortedItems[i].weight&&items[j].value==sortedItems[i].value&&sortedItems[i].taken>0) {
                items[j].taken=1;
            }
        }
    }
    return max_value;
}

bool Solver::compareItems(Item i1, Item i2) {
    double unit_cost1=(double)i1.value / i1.weight;
    double unit_cost2=(double)i2.value / i2.weight;
    return unit_cost1>unit_cost2;
}

void Solver::backtrack(int k, int n,vector<Item>& items,vector<Item>& sortedItems, int max_weight, int current_weight, int current_value, int bound, int& max_value, std::vector<int>& best_taken) {
    int i;
    if (k == n) {
        if (current_value>max_value) {
            max_value=current_value;
            for (i=0;i<n;i++) {
                sortedItems[i].taken=best_taken[i];
            }
        }
        return;
    }
    if (current_weight+sortedItems[k].weight<=max_weight) {
        best_taken[k]=1;
        current_weight+=sortedItems[k].weight;
        current_value+=sortedItems[k].value;
        backtrack(k+1,n,items,sortedItems,max_weight,current_weight,current_value,bound,max_value,best_taken);
        best_taken[k]=0;
        current_weight-=sortedItems[k].weight;
        current_value-=sortedItems[k].value;
    }
    bound=current_value;
    int j=k+1;
    int total_weight=current_weight;
    while (j<n && total_weight+sortedItems[j].weight <= max_weight) {
        total_weight+=sortedItems[j].weight;
        bound+=sortedItems[j].value;
        j++;
    }
    if (j<n) {
        bound+=(max_weight-total_weight)*(sortedItems[j].value/sortedItems[j].weight);
    }
    if (bound>max_value) {
        backtrack(k+1,n,items,sortedItems,max_weight,current_weight,current_value,bound,max_value,best_taken);
    }
}

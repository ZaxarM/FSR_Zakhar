#ifndef SOLVER_H
#define SOLVER_H
#include "Item.h"
#include <vector>
using namespace std;

class Solver {
public:
    static double knapsack_var2(vector<Item>& items, int max_weight, int n);
private:
    static void backtrack(int k,int n,vector<Item>& items,vector<Item>& sortedItems, int max_weight, int current_weight, int current_value, int bound, int& max_value, std::vector<int>& best_taken);
    static bool compareItems(Item i1, Item i2);
};
#endif // SOLVER_H

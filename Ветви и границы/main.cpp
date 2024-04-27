#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Item.h"
#include "Parser.h"
#include "Solver.h"
using namespace std;

int main() {
    Parser parser;
    if (!parser.parse("input.txt"))
        return -1;
    double totalValue = Solver::knapsack_var2(parser.items, parser.max_weight,parser.n);
    cout << "Max value: " << totalValue << endl;
    for (int i=0;i<parser.n;i++)
        cout<<parser.items[i].taken << " ";
    return 0;
}

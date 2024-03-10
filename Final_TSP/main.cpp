#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <Parcer.h>
#include <TSP_Parcer.h>
#include <DB.h>
#include <TSP_DB.h>
#include <Solver.h>
using namespace std;

int main() {
    TSP_DB database;
    database.loadDataFromFile("input.txt");
    Solver solver(database.data);
    solver.solve();
    return 0;
}

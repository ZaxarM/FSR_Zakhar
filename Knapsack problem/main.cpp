#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Parser.h"
#include "Thing.h"
#include "Solver.h"

using namespace std;


int main() {
    char inputFile[20]="input.txt";
    int pop_size=100;
    int gen_num=1000;
    Parser parser(inputFile);
    parser.parse(inputFile);
    double max_weight=parser.get_max_weight();
    const vector<Thing>t= parser.get_t();
    Solver solver;
    pair<int, vector<int>> s=solver.genetic_algorithm(t, max_weight, pop_size, gen_num);
    return 0;
}


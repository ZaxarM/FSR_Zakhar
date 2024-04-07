#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Thing.h"

class Solver {
public:
    Solver() {}
    void var(std::vector<std::pair<int, std::vector<int>>>& p, int s);
    std::pair<int, std::vector<int>> genetic_algorithm(const std::vector<Thing>& t, double max_weight, int pop_size, int gen_num);
};

#endif // SOLVER_H

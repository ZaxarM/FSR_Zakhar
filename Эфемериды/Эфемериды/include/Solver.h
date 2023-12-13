#ifndef SOLVER_H
#define SOLVER_H

#include "Parcer.h"
#include "Solution.h"
static const int DATA_COLUNNS = 6;
extern int DATA_SIZE;

class Solver {
    Parcer* parcer;

public:
    Solver(Parcer* p);
    Solution solve();

private:
    double time(double (*date)[6], double y, double m, double d, double h, double mi, double s);
    double Lagrange_interpolation(const double vel[], double t[], int n, double time);
    double calculateAverage(const double A[], double T);
};

#endif

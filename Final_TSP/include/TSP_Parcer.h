#ifndef TSP_PARCER_H
#define TSP_PARCER_H

#include <Parcer.h>
#include <fstream>
#include <iostream>
using namespace std;

class TSP_Parser : public Parcer {
public:
    vector<pair<double,double>> read(const string& filename);
};

#endif // TSP_PARCER_H

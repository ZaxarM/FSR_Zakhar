#ifndef PARCER_H
#define PARCER_H

#include <vector>
#include <string>
#include <utility>
using namespace std;

class Parcer {
public:
    virtual vector<pair<double,double>> read(const string& filename)=0;
};

#endif // PARCER_H

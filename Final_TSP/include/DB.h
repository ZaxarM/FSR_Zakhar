#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include <utility>
#include "TSP_Parcer.h"

using namespace std;

class DB {
public:
    virtual void loadDataFromFile(const string& filename) = 0;
};
#endif // DB_H

#ifndef TSP_DB_H
#define TSP_DB_H

#include "DB.h"
#include "TSP_Parcer.h"

class TSP_DB : public DB {
public:
    vector<pair<double,double>>data;
    void loadDataFromFile(const string& filename);
};

#endif // TSP_DB_H

#include "TSP_DB.h"

void TSP_DB::loadData(const string& filename) {
    TSP_Parser parser;
    data=parser.read(filename);
}


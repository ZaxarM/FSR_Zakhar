#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Item.h"
using namespace std;

class Parser {
public:
    int n;
    double max_weight;
    vector<Item> items;
public:
    bool parse(const string& filename);
};

#endif // PARSER_H


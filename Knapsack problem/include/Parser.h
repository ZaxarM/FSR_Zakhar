#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include "Thing.h"
#include <string>
using namespace std;

class Parser {
    char *filename;
    long int max_weight, n;
    vector<Thing> t;
public:
    Parser(char * filename1);
    void parse(const string &filename);
    vector<Thing> get_t();
    long int get_num();
    long int get_max_weight();
};

#endif // PARSER_H

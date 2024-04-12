#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <string>
using namespace std;

class Parser {
    string filename;
    int num_vert, num_edge;
    vector<vector<int>> adj_list;
public:
    Parser(string filename1);
    void parse();
    const vector<vector<int>>& get_list();
    int get_num_vert();
    int get_num_edge();
    string get_filename();
};

#endif // PARSER_H

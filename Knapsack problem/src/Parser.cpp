#include "Parser.h"
#include <fstream>
#include <iostream>
using namespace std;

Parser::Parser(char *filename1) {filename=filename1;}
vector<Thing> Parser::get_t() {
    return t;
}
long int Parser::get_num() {
    return n;
}
long int Parser::get_max_weight() {
    return max_weight;
}
void Parser::parse(const string& fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout<<"Parse error "<<endl;
        return;
    }
    int i,n;
    double v,w;
    inputFile>>n>>max_weight;
    for (i=0;i<n;i++){
        inputFile>>v>>w;
        Thing thing(v,w);
        t.push_back(thing);
    }
    inputFile.close();
    return;
}

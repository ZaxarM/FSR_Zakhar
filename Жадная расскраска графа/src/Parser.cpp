#include "Parser.h"
#include <fstream>
#include <iostream>

using namespace std;

Parser::Parser(string filename1) {filename=filename1;}

int Parser::get_num_vert() {
    return num_vert;
}
int Parser::get_num_edge() {
    return num_edge;
}
string Parser::get_filename(){
    return filename;
}
const vector<vector<int>>& Parser:: get_list(){
    return adj_list;
}
void Parser::parse() {
    string f_name=get_filename();
    ifstream inputFile(f_name);
    if (!inputFile.is_open()) {
        cout<<"Parse error "<<endl;
        return;
    }
    int i,u,v;
    inputFile>>num_vert>>num_edge;
    adj_list.resize(num_vert);
    for (i=0;i<num_edge;i++){
        inputFile>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    inputFile.close();
    return;
}

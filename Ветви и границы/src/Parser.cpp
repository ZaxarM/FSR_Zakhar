#include "Parser.h"

bool Parser::parse(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()){
        cout<<"Parse error"<< endl;
        return false;
    }
    inputFile>>n>>max_weight;
    items.resize(n);
    int i;
    for (i=0;i<n;i++) {
        inputFile>>items[i].value>>items[i].weight;
        items[i].taken=0;
    }
    inputFile.close();
    return true;
}

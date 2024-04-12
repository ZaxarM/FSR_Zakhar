#include <iostream>
#include "Parser.h"
#include "Solver.h"

using namespace std;

int main(){
    Parser parser("input.txt");
    parser.parse();
    Solver solver(parser.get_list());
    int n=parser.get_num_vert();
    solver.colorGraph(n);
    solver.printColors(n);
    return 0;
}

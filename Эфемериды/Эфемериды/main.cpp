#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include "Except.h"
#include "Parcer.h"
#include "Solution.h"
#include "Solver.h"
#include "Analyser.h"
#include "Presenter.h"
using namespace std;

int DATA_SIZE;

int main() {
    cin>>DATA_SIZE;
    try {
        Parcer parcer("qq.txt");
        Solver solver(&parcer);
        Solution solution = solver.solve();
        Analyser analyser;
        double analysisResult = analyser.analyse(solution);

        Presenter presenter(&solution, &parcer, &analyser);
        presenter.show_solution();
    } catch (const Except& e) {
        cerr << "Error: " << e.get_err() << " -- ";
        e.print();
        // Обработка ошибок по необходимости
    }

    return 0;
}

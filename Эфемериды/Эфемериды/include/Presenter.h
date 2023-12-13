#ifndef PRESENTERH
#define PRESENTERH
#include "Solution.h"
#include "Parcer.h"
#include "Analyser.h"

class Presenter {
    Solution* sol;
    Parcer* parcer;
    Analyser* analyser;

public:
    Presenter(Solution* s, Parcer* p, Analyser* a);
    void show_solution();
};

#endif

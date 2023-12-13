#include "Presenter.h"
#include "Except.h"
#include "Parcer.h"
#include "Solution.h"
#include "Solver.h"
#include "Analyser.h"
#include <iostream>

Presenter::Presenter(Solution* s, Parcer* p, Analyser* a) : sol(s), parcer(p), analyser(a) {}

void Presenter::show_solution() {
    std::cout << "Time scale            : "<< sol->inf[0]<<std::endl;
    std::cout << "Object                : "<< sol->inf[1]<<std::endl;
    std::cout << "Relative to           : "<< sol->inf[2]<<std::endl;
    std::cout << "Planetary theory      : "<< sol->inf[3]<<std::endl;
    std::cout << "Coordinates           : "<< sol->inf[4]<<std::endl;
    std::cout << "Equator and equinox   : "<< sol->inf[5]<<std::endl;
    std::cout << "Observer              : "<< sol->inf[6]<<std::endl;
    std::cout << "Light time correction : "<< sol->inf[7]<<std::endl;
    std::cout << "Relativistic effects  : "<< sol->inf[8]<<std::endl;
    std::cout << "Velocity X: " << sol->velX << std::endl;
    std::cout << "Velocity Y: " << sol->velY << std::endl;
    std::cout << "Velocity Z: " << sol->velZ << std::endl;
    std::cout << "Position X: " << sol->posX << std::endl;
    std::cout << "Position Y: " << sol->posY << std::endl;
    std::cout << "Position Z: " << sol->posZ << std::endl;
    std::cout << "Velocity: " << sol->velocity << std::endl;
}

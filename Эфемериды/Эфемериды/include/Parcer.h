#ifndef PARCER_H
#define PARCER_H

#include <fstream>
#include <sstream>
#include <string>
#include "Except.h"
static const int DATE_COLUMNS = 6;
extern int DATA_SIZE;
class Parcer {
    std::string filename;
    std::ifstream f_in;

public:
    Parcer(const std::string& s);
    ~Parcer();
    bool parse(std::string info[], double date[][DATE_COLUMNS], double positionX[], double positionY[], double positionZ[], double velocityX[], double velocityY[], double velocityZ[]);
};

#endif

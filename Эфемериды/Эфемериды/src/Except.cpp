#include "Except.h"
#include <iostream>

Except::Except(ErrCode code, const char* desc) : err_no(code), description(desc) {}

int Except::get_err() const {
    return static_cast<int>(err_no);
}

void Except::print() const {
    std::cout << description << std::endl;
}

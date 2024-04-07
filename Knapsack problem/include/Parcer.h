#ifndef PARCER_H
#define PARCER_H

#include <vector>
#include "item.h"
#include <string>

struct Parcer {
    static std::vector<Item> parseItems(const std::string& fileName);
};

#endif // PARSER_H

#endif // PARCER_H

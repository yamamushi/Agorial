//
// Created by Jonathan Rumion on 8/13/15.
//

#ifndef AGORIAL_ISNUMBER_H
#define AGORIAL_ISNUMBER_H

#include <string>

bool IsNumber(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

#endif //AGORIAL_ISNUMBER_H

//
// Created by Jonathan Rumion on 8/17/15.
//
// Modified from http://www.zedwood.com/article/cpp-utf8-char-to-codepoint
//


#ifndef AGORIAL_UTF8UTIL_H
#define AGORIAL_UTF8UTIL_H

#include <string>

std::string IntToUTF8String(int cp);
int UTF8StringToInt(const std::string &u);
std::string UTF8CodepointToHex(const std::string &u);

#endif //AGORIAL_ITTOUTF8_H

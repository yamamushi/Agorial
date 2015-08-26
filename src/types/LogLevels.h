/*
// Created by Jonathan Rumion on 8/24/15.

   Logging Levels:

        0 - ALL
        1 - DEBUG
        2 - ERROR
        3 - FATAL
        4 - WARN
        5 - INFO
        6 - OFF

*/

#ifndef AGORIAL_LOGLEVELS_H
#define AGORIAL_LOGLEVELS_H


enum class LogLevel{
    ALL,
    DEBUG,
    ERROR,
    FATAL,
    INFO,
    WARN,
    OFF
};

#endif //AGORIAL_LOGLEVELS_H

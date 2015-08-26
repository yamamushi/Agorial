//
// Created by Jonathan Rumion on 8/25/15.
//

#ifndef AGORIAL_TASKSPAWNER_H
#define AGORIAL_TASKSPAWNER_H

#include <async++.h>
#include <functional>
#include <string>
#include <iostream>
#include <vector>

#include "util/MsgQueue.h"

/*
 * An example class for testing the TaskSpawner class
 *
 * std::bind functions must be static, as seen by hello() and sayHello(std::string hello)
 *
 */

class TestTask{

public:

    static void hello(){std::cout << "Hello" << std::endl;}
    static void sayHello(std::string hello){ std::cout << hello << std::endl;}

};

class TaskSpawner {

public:

    void Spawn(std::function<void()> task);
    void SetTaskList(std::vector<std::function<void()> > taskList){m_taskList = taskList;}
    void Run();

private:

    std::vector<std::function<void()> > m_taskList;

};


#endif //AGORIAL_TASKSPAWNER_H

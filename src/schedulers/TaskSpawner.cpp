//
// Created by Jonathan Rumion on 8/25/15.
//

#include "TaskSpawner.h"


void TaskSpawner::Spawn(std::function<void()> task){

    async::spawn(task);

}


void TaskSpawner::Run(){

    for(auto i : m_taskList){
        Spawn(i);
    }
}
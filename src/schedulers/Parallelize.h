//
// Created by Jonathan Rumion on 8/25/15.
//

#ifndef AGORIAL_PARALLELIZE_H
#define AGORIAL_PARALLELIZE_H

#include <async++.h>
#include <functional>
#include <vector>

#include "util/MsgQueue.h"

class Parallelize {

public:

    Parallelize(std::function<void(int)> WorkerFunction, int RangeBegin, int RangeEnd, int ChunkSize)
            : m_chunkSize(ChunkSize), m_begin(RangeBegin), m_end(RangeEnd), m_workerFunction(WorkerFunction) {};

    void setChunkSize(int ChunkSize){m_chunkSize = ChunkSize;}
    void setRange(int begin, int end){m_begin = begin; m_end = end;}
    void run();


private:

    int m_chunkSize;
    int m_begin, m_end; // Ranges

    std::function<void(int)> m_workerFunction;

};


#endif //AGORIAL_PARALLELIZE_H

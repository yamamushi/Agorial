//
// Created by Jonathan Rumion on 8/25/15.
//

#include "Parallelize.h"



void Parallelize::run(){

    async::parallel_for(async::irange(m_begin, m_end), m_workerFunction);

}
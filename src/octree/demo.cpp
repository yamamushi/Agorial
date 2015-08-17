#include "octree.h"
#include <iostream>
#include <fstream>

#ifdef WIN32
#include <tchar.h>
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif
{
    Octree<double> o(4096); /* Create 4096x4096x4096 octree containing doubles. */
    //o(1,2,3) = 3.1416;      /* Put pi in (1,2,3). */

    std::ofstream myfile;
    myfile.open("output");
    o.writeBinary(myfile);
    myfile.close();
    o.erase(1,2,3);         /* Erase that node. */
    std::ifstream infile;
    infile.open("output");
    o.readBinary(infile);
    std::cout << o.at(1,2,3) << std::endl;

	return 0;
}


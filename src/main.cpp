#include <iostream>

#include "pathfinder.h"


int main()
{

    PathFinder i;

    i.setInputFileName("input.txt");
    i.setOutputFileName("output.txt");

    if(i.getInputData()== false)
    {
        return 0;
    }

    if(i.solveMaze()==false)
    {
       return 0;
    }

    if(i.saveOutputData()==false)
    {
        return 0;
    }

    return 0;
}

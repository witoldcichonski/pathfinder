#include <iostream>
#include <fstream>
#include <cstring>
#include <deque>
#include "pathfinder.h"

PathFinder::PathFinder()
{

}

void PathFinder::setInputFileName(std::string fileName)
{
    m_inputFile = fileName;
}

void PathFinder::setOutputFileName(std::string fileName)
{
    m_outputFile = fileName;
}

bool PathFinder::openInputFile()
{
    inputStream.open(m_inputFile, std::fstream::in);

    if(!inputStream.is_open())
    {
        std::cout<<"Input file was not opened"<<std::endl;
        return false;
    }

    return true;
}

bool PathFinder::getInputData()
{
    if( openInputFile() == false)
    {
        return false;
    }

   if(  readMazeSizeFromFile()== false)
    {
        return false;
    }

    if( readRowMazeFromFile()== false)
    {
        return false;
    }

    closeInputFile();

    return true;

}

bool PathFinder::saveOutputData()
{
    applyPathOnRawMaze();

    if( openOutputFile() == false)
    {
        return false;
    }

    printOutput();

    claseOutputFile();

    return true;

}

bool PathFinder::solveMaze()
{

    if(convertRowIntoBinaryMaze()== false)
    {
        return false;
    }

    if(runLeeAlgorithm()== false)
    {
        return false;
    }

return true;

}

//TODO: exceptions handling from stoi - return false
//add tests strings - words
bool PathFinder::readMazeSizeFromFile()
{
    std::string singleLine;
    singleLine.clear();

    getline(inputStream, singleLine);

    if(!inputStream.eof())
    {
        col = stoi(singleLine);
        singleLine.clear();
    }
    else
    {
        std::cout<<"Maze size is misssing"<<std::endl;
        return false;
    }

    getline(inputStream, singleLine);

    if(!inputStream.eof())
    {
        row = stoi(singleLine);
    }
    else
    {
        std::cout<<"Maze size is misssing"<<std::endl;
        return false;
    }

    return true;
}

bool PathFinder::readRowMazeFromFile()
{

    rawMaze = new char *[row];
    for(int i = 0; i <row; i++)
    {
        rawMaze[i] = new char[col];
    }

    std::string singleLine;
    singleLine.clear();

    for(auto i=0; i < row; i++)
    {
        if(!inputStream.eof())
        {
            getline(inputStream, singleLine);

            if(singleLine.size() == col)
            {
                strncpy(rawMaze[i],singleLine.c_str(),singleLine.size());
                singleLine.clear();
            }
            else
            {
                std::cout<<"Invalid maze width"<<std::endl;
                return false;
            }
        }
        else
        {
            std::cout<<"Invalid maze length"<<std::endl;
            return false;
        }

    }

    return true;
}

void PathFinder::closeInputFile()
{
     inputStream.close();
}

bool PathFinder::convertRowIntoBinaryMaze()
{
    binMaze = new int *[row];
    for(auto i = 0; i <row; i++)
    {
        binMaze[i] = new int[col];
    }

    bool startPoint = false;
    bool endPoint = false;

    for(auto i=0; i < row; i++)
    {
        for(auto j=0; j < col; j++)
        {

            if(rawMaze[i][j] == '#')
            {
                binMaze[i][j]=0;
            }
            else if(rawMaze[i][j] == ' ')
            {
                binMaze[i][j]=1;
            }
            else if(rawMaze[i][j] == 'S')
            {
                start[0] = i;
                start[1] = j;
                binMaze[i][j]=2;
                startPoint = true;
            }
            else if(rawMaze[i][j] == 'E')
            {
                end[0] = i;
                end[1] = j;
                binMaze[i][j]=3;
                endPoint = true;
            }
            else
            {
                std::cout<<"Invalid symbol in maze"<<std::endl;
                return false;
            }
        }
    }

    if(!(startPoint && endPoint))
    {
        std::cout<<"Start or end point is missing"<<std::endl;
        return false;
    }

    return true;

}

bool PathFinder::runLeeAlgorithm()
{

    int hor[] = { -1, 0, 0, 1 };
    int ver[] = { 0, -1, 1, 0 };

    bool checkedMaze[row][col];
    memset(checkedMaze, false, sizeof(checkedMaze));

    std::deque<Point> q;

    int a = start[0];
    int b = start[1];

    checkedMaze[a][b] = true;

    q.push_back({a, b, 1});

    minDist = (int)row*col;

    int it = 0;
    while(it<q.size())
    {

        Point currentPoint = q.at(it);
        it++;

        if (currentPoint.x == end[0] && currentPoint.y == end[1])
        {
            minDist = currentPoint.dist;
            break;
        }

        for (auto k = 0; k < MOVE_OPTIONS; k++)
        {
            Point newPoint = currentPoint;

            newPoint.x += ver[k];
            newPoint.y += hor[k];
            newPoint.dist +=1;

            bool  isChecked= checkedMaze[newPoint.x][newPoint.y];

            if (isValid(isChecked,newPoint.x, newPoint.y))
            {
                checkedMaze[newPoint.x][newPoint.y] = true;
                q.push_back(newPoint);
            }
        }
    }

    if (minDist != (int)row*col)
    {
        savePath(q, it);
    }
    else
    {
        std::cout << "Invalid maze to solve. Check input file."<<std::endl;
        return false;
    }

    return true;


}

bool PathFinder::isValid(bool isChecked, int ver, int hor)
{
    return (hor >= 0) && (hor < col) && (ver >= 0) && (ver < row)
            && binMaze[ver][hor] && !isChecked;
}

void PathFinder::savePath(std::deque<Point> &points, int it )
{
    int p;
    for(p =0; p<points.size(); p++)
    {
        if( points.at(p).x==end[0] && points.at(p).y==end[1] )
        {
            break;
        }
    }


    Point currentPoint = points.at(p);
    path.push_back(points.at(p));

    for(auto i = p; i>=0; i--)
    {
        if(isCorrectNode(currentPoint, points.at(i)))
        {
            path.push_back(points.at(i));
            currentPoint = points.at(i);
        }
    }
}

bool PathFinder::isCorrectNode(Point currentPoint, Point nextPoint)
{
    return (currentPoint.dist-nextPoint.dist == 1) &&
            ((currentPoint.x - nextPoint.x == 0) && (abs(currentPoint.y - nextPoint.y) == 1)) ||
            ((abs(currentPoint.x - nextPoint.x) == 1) && (currentPoint.y - nextPoint.y == 0));

}

void PathFinder::applyPathOnRawMaze()
{
    for(auto i=0; i < path.size(); i++)
    {
        rawMaze[path.at(i).x][path.at(i).y] = '*';
    }
}

bool PathFinder::openOutputFile()
{
    outputStream.open(m_outputFile, std::fstream::out | std::fstream::trunc );

    if(!outputStream.is_open())
    {
        std::cout<<"Output file was not opened"<<std::endl;
        return false;
    }

    return true;
}


void PathFinder::claseOutputFile()
{
    outputStream.close();
}

void PathFinder::printOutput()
{
    std::string singleLine;

    for(auto i =0; i<row; i++)
    {
        singleLine.assign(rawMaze[i], col);
        outputStream<< singleLine<<std::endl;
    }

    outputStream<<minDist;
}

int PathFinder::getMazeLength()
{
    return row;
}
int PathFinder::getMazeWidth()
{
    return col;
}
void PathFinder::getStartPoint(int *startPoint)
{
    startPoint[0] = start[0];
    startPoint[1] = start[1];
}
void PathFinder::getEndPoint(int *endPoint)
{
    endPoint[0] = end[0];
    endPoint[1] = end[1];
}
int PathFinder::getPathLength()
{
    return minDist;
}

PathFinder::~PathFinder()
{

}

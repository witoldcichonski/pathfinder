#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <cstdint>

const int COORDINATES = 2;
const int MOVE_OPTIONS = 4;

class PathFinder
{
public:
    PathFinder();

    void setInputFileName(const std::string &fileName);
    void setOutputFileName(const std::string &fileName);
    bool getInputData();
    bool solveMaze();
    bool saveOutputData();
    int getMazeLength() const;
    int getMazeWidth() const;
    void getStartPoint(int *startPoint) const;
    void getEndPoint(int *endPoint) const;
    int getPathLength() const;

    ~PathFinder();
private:


    std::string m_inputFile;
    std::string m_outputFile;
    std::fstream inputStream;
    std::fstream outputStream;
    int col;
    int row;
    std::vector<std::vector <char>> rawMaze;
    std::vector<std::vector<int>> binMaze;

    int minDist;
    int start[COORDINATES];
    int end[COORDINATES];
    struct Point
    {
        int x;
        int y;
        int dist;
    };

    std::vector<Point> path;

    bool openInputFile();
    bool readMazeSizeFromFile();
    bool readRowMazeFromFile();
    void closeInputFile();
    bool convertRowIntoBinaryMaze();
    bool runLeeAlgorithm();
    bool isValid(bool isChecked, int ver, int hor);
    void savePath(std::deque<Point> &points);
    bool isCorrectNode(Point currentPoint, Point nextPoint);
    void applyPathOnRawMaze();
    bool openOutputFile();
    void claseOutputFile();
    void printOutput();

};

#endif // PATHFINDER_H


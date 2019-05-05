#include "gtest/gtest.h"
#include "pathfinder.h"



TEST(invalidInputData, inValidFileName)
{

    PathFinder i;
    i.setInputFileName("XXX.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(invalidInputData, invalidMazeValueCol)
{

    PathFinder i;
    i.setInputFileName("invalidMazeValueCol.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(invalidInputData, invalidMazeValueRow)
{

    PathFinder i;
    i.setInputFileName("invalidMazeValueRow.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(invalidInputData, invalidMazeSizeWidth)
{
    PathFinder i;
    i.setInputFileName("invalidMazeSizeRaw.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(invalidInputData, invalidMazeSizeLenght)
{
    PathFinder i;
    i.setInputFileName("invalidMazeSizeRaw.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(validInputData, correctInputData)
{

    PathFinder i;
    i.setInputFileName("correctInputData.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 4);
    ASSERT_EQ(i.getMazeWidth(), 4);

}


TEST(invalidInputData, invalidSymbolInputData)
{

    PathFinder i;
    i.setInputFileName("invalidSymbolInputData.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 4);
    ASSERT_EQ(i.getMazeWidth(), 4);

    ASSERT_EQ(i.solveMaze(), false);

}

TEST(invalidInputData, missingEndInputData)
{

    PathFinder i;
    i.setInputFileName("missingEndInputData.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 4);
    ASSERT_EQ(i.getMazeWidth(), 4);

    ASSERT_EQ(i.solveMaze(), false);

}

TEST(invalidInputData, missingStartInputData)
{

    PathFinder i;
    i.setInputFileName("missingStartInputData.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 4);
    ASSERT_EQ(i.getMazeWidth(), 4);

    ASSERT_EQ(i.solveMaze(), false);
}

TEST(invalidInputData, lackOfConnectionStartEnd)
{
    int start[COORDINATES];
    int stop[COORDINATES];

    PathFinder i;
    i.setInputFileName("lackOfConnectionStartEnd.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 12);
    ASSERT_EQ(i.getMazeWidth(), 9);

    ASSERT_EQ(i.solveMaze(), false);
}

TEST(validInputData, correctMaze)
{
    int start[COORDINATES];
    int stop[COORDINATES];

    PathFinder i;
    i.setInputFileName("correctMaze.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 12);
    ASSERT_EQ(i.getMazeWidth(), 9);

    ASSERT_EQ(i.solveMaze(), true);

    i.getStartPoint(start);
    ASSERT_EQ(start[0], 10);
    ASSERT_EQ(start[1], 10);

    i.getEndPoint(stop);
    ASSERT_EQ(stop[0], 1);
    ASSERT_EQ(stop[1], 1);

    ASSERT_EQ(i.getPathLength(),16);

}

TEST(invalidOutputFile, correctMaze)
{
    int start[COORDINATES];
    int stop[COORDINATES];

    PathFinder i;
    i.setInputFileName("correctMaze.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 12);
    ASSERT_EQ(i.getMazeWidth(), 9);

    ASSERT_EQ(i.solveMaze(), true);

    i.getStartPoint(start);
    ASSERT_EQ(start[0], 10);
    ASSERT_EQ(start[1], 10);

    i.getEndPoint(stop);
    ASSERT_EQ(stop[0], 1);
    ASSERT_EQ(stop[1], 1);

    ASSERT_EQ(i.getPathLength(),16);
    i.setInputFileName("xx.txt");

    ASSERT_EQ(i.saveOutputData(), false);

}

TEST(validOutputFile, correctMaze)
{
    int start[COORDINATES];
    int stop[COORDINATES];

    PathFinder i;
    i.setInputFileName("correctMaze.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 12);
    ASSERT_EQ(i.getMazeWidth(), 9);

    ASSERT_EQ(i.solveMaze(), true);

    i.getStartPoint(start);
    ASSERT_EQ(start[0], 10);
    ASSERT_EQ(start[1], 10);

    i.getEndPoint(stop);
    ASSERT_EQ(stop[0], 1);
    ASSERT_EQ(stop[1], 1);

    ASSERT_EQ(i.getPathLength(),16);
    i.setInputFileName("output.txt");

    ASSERT_EQ(i.saveOutputData(), true);

}




#include "gtest/gtest.h"
#include "pathfinder.h"

TEST(example, subtract)
{
    PathFinder i;

    i.setInputFileName("testFiles/input.txt");

    ASSERT_EQ(i.getInputData(), true);
}


TEST(invalidInputData, inValidFileName)
{

    PathFinder i;
    i.setInputFileName("testFiles/XXX.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(invalidInputData, invalidMazeValueCol)
{

    PathFinder i;
    i.setInputFileName("testFiles/invalidMazeValueCol.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(invalidInputData, invalidMazeValueRow)
{

    PathFinder i;
    i.setInputFileName("testFiles/invalidMazeValueRow.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(invalidInputData, invalidMazeSizeWidth)
{
    PathFinder i;
    i.setInputFileName("testFiles/invalidMazeSizeRaw.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(invalidInputData, invalidMazeSizeLenght)
{
    PathFinder i;
    i.setInputFileName("testFiles/invalidMazeSizeRaw.txt");
    ASSERT_EQ(i.getInputData(), false);
}

TEST(validInputData, correctInputData)
{

    PathFinder i;
    i.setInputFileName("testFiles/correctInputData.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 4);
    ASSERT_EQ(i.getMazeWidth(), 4);

}


TEST(invalidInputData, invalidSymbolInputData)
{

    PathFinder i;
    i.setInputFileName("testFiles/invalidSymbolInputData.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 4);
    ASSERT_EQ(i.getMazeWidth(), 4);

    ASSERT_EQ(i.solveMaze(), false);

}

TEST(invalidInputData, missingEndInputData)
{

    PathFinder i;
    i.setInputFileName("testFiles/missingEndInputData.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 4);
    ASSERT_EQ(i.getMazeWidth(), 4);

    ASSERT_EQ(i.solveMaze(), false);

}

TEST(invalidInputData, missingStartInputData)
{

    PathFinder i;
    i.setInputFileName("testFiles/missingStartInputData.txt");

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
    i.setInputFileName("testFiles/lackOfConnectionStartEnd.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 9);
    ASSERT_EQ(i.getMazeWidth(), 12);

    ASSERT_EQ(i.solveMaze(), false);
}

TEST(validInputData, correctMaze)
{
    int start[COORDINATES];
    int stop[COORDINATES];

    PathFinder i;
    i.setInputFileName("testFiles/correctMaze.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 9);
    ASSERT_EQ(i.getMazeWidth(), 12);

    ASSERT_EQ(i.solveMaze(), true);

    i.getStartPoint(start);
    ASSERT_EQ(start[0], 7);
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
    i.setInputFileName("testFiles/correctMaze.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 9);
    ASSERT_EQ(i.getMazeWidth(), 12);

    ASSERT_EQ(i.solveMaze(), true);

    i.getStartPoint(start);
    ASSERT_EQ(start[0], 7);
    ASSERT_EQ(start[1], 10);

    i.getEndPoint(stop);
    ASSERT_EQ(stop[0], 1);
    ASSERT_EQ(stop[1], 1);

    ASSERT_EQ(i.getPathLength(),16);
    i.setInputFileName("testFiles/xx.txt");

    ASSERT_EQ(i.saveOutputData(), false);

}

TEST(validOutputFile, correctMaze)
{
    int start[COORDINATES];
    int stop[COORDINATES];

    PathFinder i;
    i.setInputFileName("testFiles/correctMaze.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 9);
    ASSERT_EQ(i.getMazeWidth(), 12);

    ASSERT_EQ(i.solveMaze(), true);

    i.getStartPoint(start);
    ASSERT_EQ(start[0], 7);
    ASSERT_EQ(start[1], 10);

    i.getEndPoint(stop);
    ASSERT_EQ(stop[0], 1);
    ASSERT_EQ(stop[1], 1);

    ASSERT_EQ(i.getPathLength(),16);
    i.setOutputFileName("testFiles/output.txt");

    ASSERT_EQ(i.saveOutputData(), true);

}

TEST(validOutputFile, littleMaze)
{
    int start[COORDINATES];
    int stop[COORDINATES];

    PathFinder i;
    i.setInputFileName("testFiles/littleMaze.txt");

    ASSERT_EQ(i.getInputData(), true);
    ASSERT_EQ(i.getMazeLength(), 1);
    ASSERT_EQ(i.getMazeWidth(), 3);

    ASSERT_EQ(i.solveMaze(), true);

    i.getStartPoint(start);
    ASSERT_EQ(start[0], 0);
    ASSERT_EQ(start[1], 0);

    i.getEndPoint(stop);
    ASSERT_EQ(stop[0], 0);
    ASSERT_EQ(stop[1], 2);

    ASSERT_EQ(i.getPathLength(),3);
    i.setOutputFileName("testFiles/output.txt");

    ASSERT_EQ(i.saveOutputData(), true);

}

TEST(validOutputFile, bigMaze)
{
    int start[COORDINATES];
    int stop[COORDINATES];

    PathFinder i;
    i.setInputFileName("testFiles/stringInputMaze.txt");

    ASSERT_EQ(i.getInputData(), false);

}




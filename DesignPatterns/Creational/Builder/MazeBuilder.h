#ifndef MAZE_BUILDER_H
#define MAZE_BUILDER_H

#include "../Maze.h"

class MazeBuilder
{
public:
    MazeBuilder() {};
    virtual void BuildMaze() { }
    virtual void BuildRoom(int roomNumber) { }
    virtual void BuildDoor(int roomFrom, int roomTo) {}
    virtual Maze* GetMaze() { return NULL; }

};

#endif

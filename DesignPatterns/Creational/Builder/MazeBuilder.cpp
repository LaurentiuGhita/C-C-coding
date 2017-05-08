#include "MazeBuilder.h"

Maze* CreateMaze(MazeBuilder& builder)
{
    builder.BuildMaze();
    builder.BuildRoom(1);
    builder.BuildRoom(2);
    builder.BuildDoor(1,2);

    std::cout << "Build maze \n";
    return builder.GetMaze();
}


int main()
{
    MazeBuilder b;

    CreateMaze(b);
}
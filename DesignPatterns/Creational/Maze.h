#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>

enum Direction { North, South, East, West };

class MapSite
{
public:
        virtual void Enter() = 0;
};

class Room : public MapSite 
{
    Room(int nRoomNo);

    MapSite* GetSide(Direction) const; 
    void SetSide(Direction, MapSite*);

    void Enter();
protected:
    MapSite* _sides[4];
    int _roomNumber;
};


class Wall : public MapSite
{
public:
    Wall() {} 
    void Enter() { std::cout << "Entered wall \n"; }
};

class Door : public MapSite
{
public:
    Door(Room* = NULL, Room* = NULL);
    void Enter();
    Room* OtherSideFrom(Room*);
protected:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

class Maze
{
public:
    Maze() {};

    void AddRoom(Room* r) { _rooms.push_back(r); }
    Room* RoomNo(int index) const;
protected:
    std::vector<Room*> _rooms;
};

#endif

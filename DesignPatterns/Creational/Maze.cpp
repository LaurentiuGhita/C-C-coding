#include "Maze.h"

Room::Room(int number) : _roomNumber(number)
{
    for(int i = 0; i < 4; ++i)
    {
        _sides[i] = NULL;
    }
}


MapSite* Room::GetSide(Direction dir) const
{
    return _sides[dir];
} 


void Room::SetSide(Direction dir, MapSite* neighbour)
{
    _sides[dir] = neighbour; 
}

void Room::Enter()
{
    std::cout << "Entered room number " << _roomNumber << "\n";
}


Door::Door(Room* r1, Room* r2) : _room1(r1), _room2(r2)
{
    _isOpen = false;
}

void Door::Enter()
{
    if(_isOpen)
        std::cout << "Entered door \n";
    else
        std::cout << "Door closed \n";
}

Room* Door::OtherSideFrom(Room* r)
{
    if(r == _room1)
        return _room2;
    if(r == _room2)
        return _room1;

    return NULL;
}

Room* Maze::RoomNo(int index) const
{
    if(index < _rooms.size())
        return _rooms[index];

    return NULL;
}


int main()
{
}
#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <cstring>

using namespace std;

Room::Room()
{
  roomName = new char[100];
  int index = 0;
  map<char[100], Room*> roomMap;
  vector<Room::Item*> itemsInRoom;
  vector<char*> roomExits;
  description = new char[1000];
}

void Room::setName(char* name)
{
  roomName = name;
}

void Room::setExit(char* direction, Room* room)
{
  roomMap.emplace(direction, room);
  roomExits.push_back(direction);
}

void Room::setDescription(char* newDescription)
{
  description = newDescription;
}

//prints room name, description, exits, and items
void Room::printInfo()
{
  cout << "You are in " << roomName << endl;
  cout << description << endl;
  cout << "Exits: ";
  for(int i = 0; i < roomExits.size(); i++)
  {
    cout << roomExits[i] << ", ";
  }
  cout << endl;
  cout << "Items: ";
  for(int i = 0; i < itemsInRoom.size(); i++)
  {
    cout << itemsInRoom[i] << ", ";
  }
}

vector<Room::Item*> Room::getItems()
{
  return itemsInRoom;
}

//will remove an item from the room if it exists. if item does not exist, will return false
bool Room::itemRemoved(char* itemName) 
{
  for(int i = 0; i < itemsInRoom.size(); i++)
  {
    if(strcmp(itemsInRoom[i]->name, itemName) == 0)
    {
      itemsInRoom.erase(itemsInRoom.begin() + i);
      index = i;
      return true;
    }
  }
  cout << "this item does not exist";
  return false;
}

void Room::addItem(Room::Item* item)
{
  itemsInRoom.push_back(item);
}



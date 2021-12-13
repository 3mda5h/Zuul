#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <cstring>

using namespace std;

Room::Room(const char* name, const char* description)
{
  roomName = new char[100];
  strcpy(roomName, name);
  roomDescription = new char[1000];
  strcpy(roomDescription, description);
  int index = 0;
  map<const char*, Room*> roomMap;
  vector<Room::Item*> itemsInRoom;
  vector<const char*> roomExits;
}

void Room::setExit(const char* direction, Room* room)
{
  roomMap.emplace(direction, room);
  roomExits.push_back(direction);
}

//prints room name, description, exits, and items
void Room::printInfo()
{
  cout << "You are in " << roomName << endl;
  cout << roomDescription << endl;
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




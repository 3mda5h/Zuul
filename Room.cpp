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
  map<char[100], Room> roomMap;
  vector<Room::Item*> itemsInRoom;
  vector<char[100]> exitList;
  description = new char[1000];
}

void Room::setExit(char* direction, Room* room)
{
  roomMap.emplace(direction, room);
  exitList.push_back(direction);
}

void Room::setDescription(char* newDescription)
{
  description = newDescription;
}

void Room::printDescription()
{
  cout << description << endl;
  cout << "Exits: ";
  for(int i = 0; i < exitList.size(); i++)
  {
    cout << exitList[i] << ", ";
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

char* Room::getName()
{
  return roomName;
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

void Room::addItem(Item* item)
{
  itemsInRoom.push_back(item);
}



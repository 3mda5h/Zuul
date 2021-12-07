#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <cstring>
#include "main.cpp"

using namespace std;

Room::Room()
{
  roomName = new char[100];
  map<int, int> roomMap;
  vector<Item*> itemsInRoom;
  int index;
}

vector<Item*> Room::getItems()
{
  return itemsInRoom;
}

char* Room::getName()
{
  return roomName;
}

void Room::removeItem(char[100] itemName) 
{
  if(containsItem(itemName) == true)
  {
    itemsInRoom.erase(itemsInRoom.begin + index);
  }
}

void Room::addItem(Item* item)
{
  itemsInRoom.push_back(item);
}

bool Room::containsItem(char[100] itemName)
{
  for(int i = 0; i < itemsInRoom.size(); i++)
  {
    if(strcmp(itemsInRoom[i]->name, itemName) == 0)
    {
      return true;
      index = 1;
    }
  }
  return false;
}


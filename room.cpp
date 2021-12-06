#include <iostream>
#include "room.h"
#include <vector>
#include <map>
#include <cstring>

using namespace std;

Room::Room()
{
  roomName = new char[100];
  map<int, int> roomMap;
  vector<Item*> itemsInRoom;
}

struct Item
{
  char name[100];
};

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
  bool itemExists = false;
  for(int i = 0; i < itemsInRoom.size(); i++)
  {
    if(strcmp(itemsInRoom[i]->name, itemName) == 0)
    {
      itemExists = true;
      itemsInRoom.erase(itemsInRoom.begin + 1);
    }
  }
  if(itemExists == false)
  {
    cout << roomName << "does not contain a/an " << itemName << endl;
  }
}

void Room::addItem(Item* item)
{
  itemsInRoom.push_back(item);
}
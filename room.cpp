#include <iostream>
#include "room.h"
#include <vector>
#include <map>

using namespace std;

Room::Room()
{
  name = new char[100];
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
  return name;
}
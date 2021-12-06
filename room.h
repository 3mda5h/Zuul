#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector> 

using namespace std;

class Room
{
  public:
  Room();
  struct Item();
  Item::name; 
  vector<Item*> getItems();
  char* getName();
  void removeItem(char[100] itemName);
  void addItem(Item* item);
  vector<Item*> itemsInRoom();
  char* roomName;
};

#endif
#ifndef ROOM_H
#define ROOM_H

#include <iostream> 

using namespace std;

class Room
{
  public:
  Room();
  struct Item();
  vector* getItems();
  name* getName();
  vector itemsInRoom();
  char* name;
};

#endif
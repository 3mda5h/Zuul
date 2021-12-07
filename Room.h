#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector> 

using namespace std;

class Room
{
  public:
    Room();
    vector<Item*> getItems();
    int index;
    char* getName();
    void removeItem(char[100] itemName);
    void addItem(Item* item);
    bool containsItem(char[100] itemName);
    vector<Item*> itemsInRoom();
    char* roomName;
};

#endif
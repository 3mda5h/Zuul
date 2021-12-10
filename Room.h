#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector> 
#include <map>

using namespace std;

struct Item
{
  char name[100];
};

class Room
{
  public:  
    struct Item
    {
      char name[100];
    };
    Room();
    char* roomName;
    int index;
    map<int, int> roomMap;
    vector<Room::Item*> itemsInRoom;
    vector<char[100]> exitList;
    char* description;
    void setExit(char* direction, Room* room);
    void setDescription(char* description);
    void printDescription();
    vector<Room::Item*> getItems();
    char* getName();
    bool itemRemoved(char* itemName);
    void addItem(Item* item);
};

#endif
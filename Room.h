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
    Room(const char* name, const char* description);
    char* roomName;
    char* roomDescription;
    map<const char*, Room*> roomMap;
    vector<Room::Item*> itemsInRoom;
    vector<const char*> roomExits;
    void setExit(const char* direction, Room* room);
    void printInfo();
    vector<Room::Item*> getItems();
    void removeItem(int index);
    int containsItem(char* itemName);
    void addItem(Room::Item* item);
};

#endif
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector> 
#include <map>

using namespace std;

struct Item
{
  name = new char[100];
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
    map<char[100], Room*> roomMap;
    vector<Room::Item*> itemsInRoom;
    vector<char*> roomExits;
    char* description;
    void setName(char*);
    void setExit(char* direction, Room* room);
    void setDescription(char* description);
    void printInfo();
    vector<Room::Item*> getItems();
    bool itemRemoved(char* itemName);
    void addItem(Room::Item* item);
};

#endif
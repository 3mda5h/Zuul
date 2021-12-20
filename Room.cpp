#include <iostream>
#include "Room.h"
#include <vector>
#include <iterator>
#include <map>
#include <cstring>

using namespace std;

Room::Room(const char* description)
{
  roomDescription = new char[1000];
  strcpy(roomDescription, description);
  map<const char*, Room*> roomMap;
  vector<Room::Item*> itemsInRoom;
  vector<const char*> roomExits;
}

//adds key (cardinal direction) with its associated value (room) to map
void Room::setExit(const char* direction, Room* room)
{
  roomMap.emplace(direction, room);
  roomExits.push_back(direction);
}

//prints room name, description, exits, and items
void Room::printInfo()
{
  cout << "-----------------------" << endl;
  cout << roomDescription << endl; 
  
  //print rooms 
  cout << "Items: ";
  if(itemsInRoom.size() > 0)
  {
    for(int i = 0; i < itemsInRoom.size(); i++)
    {
      if(i == itemsInRoom.size() - 1) //last item no comma yes i care this much
      {
        cout << itemsInRoom[i]->name;
      }
      else
      {
        cout << itemsInRoom[i]->name << ", ";
      }
    }  
  }
  else
  {
    cout << "none";
  }
  cout << endl;
  
  //print exits
  cout << "Exits: ";
  if(roomExits.size() > 0)
  {
    for(int i = 0; i < roomExits.size(); i++)
    {
      if(i == roomExits.size() - 1) //last item no comma hehehehehe
      {
        cout << roomExits[i];
      }
      else
      {
        cout << roomExits[i] << ", ";
      }
    }
  }
  else
  {
    cout << "none";
  }
  cout << endl;
}

//returns vector of items in room
vector<Room::Item*> Room::getItems()
{
  return itemsInRoom;
}

//will remove an item from the room if it exists. if item does not exist, will return false
void Room::removeItem(int index) 
{
  itemsInRoom.erase(itemsInRoom.begin() + index);
}

//if contains item, returns its index. if not, returns -1. maybe this is a stupid way of doing this but the thing is I don't really care :D
int Room::containsItem(const char* itemName) {
  for(int i = 0; i < itemsInRoom.size(); i++)
  {
    if(strcmp(itemsInRoom[i]->name, itemName) == 0)
    {
      return i;
    }
  }
  return -1;
}

//adds item to vector of items in room
void Room::addItem(Room::Item* item)
{
  itemsInRoom.push_back(item);
}




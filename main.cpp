#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <cstring>

using namespace std;

Room::Item* newItem(const char* name);
void pickUpItem(Room* currentRoom, vector<Room::Item*>& inventory);
void dropItem(Room* currentRoom, vector<Room::Item*>& inventory, int &index);
void move(Room* currentRoom);
bool inventoryContains(vector<Room::Item*>& inventory, char* itemName, int &index);

int main() 
{
  vector<Room::Item*> inventory;
  Room* currentRoom;
  int inventoryIndex;
  bool running = true;
  char input[100];
 
  //create rooms
  Room* oneTwenty = new Room("room 1-20", "You are haning out in room 1-20. You are 100% doing C++ programming and not bio homework.");
  Room* oneHall = new Room("one hall", "extremely crowded");
  Room* oneNine = new Room("1-9", "you enter the room and instantly run away screaming. IB biology is very scary");
  
  //set exits
  oneTwenty->setExit("NORTH", oneHall); //idk if it's actually north
  
  //set items
  oneTwenty->addItem(newItem("COMPUTER"));
  
  currentRoom = oneTwenty;
  do
  {
    //win & lose conditions


    currentRoom->printInfo();
    cout << "enter PICK UP, DROP, MOVE, or QUIT" << endl;
    cin.getline(input, 100);
    {
      if(strcmp(input, "PICK UP") == 0)
      {
        pickUpItem(currentRoom, inventory);
      }
      if(strcmp(input, "DROP") == 0)
      {
        dropItem(currentRoom, inventory, inventoryIndex);
      }
      if(strcmp(input, "MOVE") == 0)
      {
        move(currentRoom);
      }
      if(strcmp(input, "QUIT") == 0)
      {
        running = false;
      }
    }
  } while(running == true);
} 

//creates a new item
Room::Item* newItem(const char* itemName)
{
  Room::Item* item = new Room::Item();
  strcpy(item->name, itemName);
  return item;
}

//adds item to player inventory, removes it from the room 
void pickUpItem(Room* currentRoom, vector<Room::Item*>& inventory)
{
  char itemName[100];
  cout << "enter the name of the item you want to pick up" << endl;
  cin.getline(itemName, 100);
  if(currentRoom->itemRemoved(itemName) == true)
  {
    vector<Room::Item*> temp = currentRoom->getItems();
    inventory.push_back(temp[currentRoom->index]);
    return;
  }
}

//removes item from player inventory, adds it to the current room
void dropItem(Room* currentRoom, vector<Room::Item*>& inventory, int &index)
{
  char itemName[100];
  cout << "enter the name of the item you want to drop" << endl;
  cin.getline(itemName, 100);
  if(inventoryContains(inventory, itemName, index) == true)
  {
    inventory.erase(inventory.begin() + currentRoom->index);
    currentRoom->addItem(inventory[currentRoom->index]);
    return;
  }
  cout << "this item is not in your inventory" << endl;
}

//changes current room based on exit chosen
void move(Room* currentRoom)
{
  char input[100];
  cout << "which exit?" << endl;
  cin.getline(input, 100);
  for(int i = 0; i < currentRoom->roomExits.size(); i++)
  {
    if(strcmp(currentRoom->roomExits[i], input) == 0)
    {
      map<const char*, Room*> temp;
      temp = currentRoom->roomMap;
      currentRoom = temp.at(input);
    }
  }
}

bool inventoryContains(vector<Room::Item*>& inventory, char* itemName, int &index)
{
  for(int i = 0; i < inventory.size(); i++)
  {
    if(strcmp(inventory[i]->name, itemName) == 0)
    {
      return true;
      index = i;
    }
  }
  return false;
}

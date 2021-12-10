#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <cstring>

using namespace std;

Room* newRoom(char* name, char* description);
Room::Item* newItem(char* name);
void pickUpItem(Room* currentRoom, vector<Room::Item*>& inventory);
void dropItem(Room* currentRoom, vector<Room::Item*>& inventory);
void move(Room* currentRoom);

int main() 
{
  vector<Room::Item*> inventory;
  Room* currentRoom = new Room();
  bool running = true;
  char input[100];
 
  //creat rooms
  Room* oneTwenty = newRoom("room 1-20", "You are haning out in room 1-20. You are 100% doing C++ programming and not bio homework.");
  Room* oneHall = newRoom("one hall", "extremely crowded");
  
  //set exits
  oneTwenty->setExit("north", oneHall); //idk if it's actually north
  
  //set items
  oneTwenty->addItem(newItem("computer"));
  
  currentRoom = oneTwenty;
  do
  {
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
        dropItem(currentRoom, inventory);
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

Room* newRoom(char* name, char* description)
{
  Room* room = new Room(); 
  room->setName(name);
  room->setDescription(description);
}

//creates a new item
Room::Item* newItem(char* itemName)
{
  Room::Item* item = new Room::Item();
  strcpy(item->name, itemName);
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
void dropItem(Room* currentRoom, vector<Room::Item*>& inventory)
{
  char itemName[100];
  cout << "enter the name of the item you want to drop" << endl;
  cin.getline(itemName, 100);
  for(int i = 0; i < inventory.size(); i++)
  {
    if(strcmp(inventory[i]->name, itemName) == 0)
    {
      inventory.erase(inventory.begin() + currentRoom->index);
      currentRoom->addItem(inventory[currentRoom->index]);
      return;
    }
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
      map<char[100], Room*> temp;
      temp = currentRoom->roomMap;
      currentRoom = temp.at(input);
    }
  }
}

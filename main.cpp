#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <cstring>

using namespace std;

Room::Item* newItem(const char* name);
void pickUpItem(Room* currentRoom, vector<Room::Item*>& inventory);
void dropItem(Room* currentRoom, vector<Room::Item*>& inventory);
void move(Room* currentRoom);
int inventoryContains(vector<Room::Item*>& inventory, const char* itemName);
void printInventory(vector<Room::Item*> inventory);

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
  currentRoom->printInfo();
  do
  {
    //win & lose conditions hehehehe
    if(currentRoom != oneTwenty && inventoryContains(inventory, "COMPUTER") < -1)
    {
      cout << "you just stole a computer from 1-20!! D:< That is a crime. You lose" << endl;
      running = false;
    }
    do
    {
      //for case sensitivity as usual
      cout << "type PICK UP, DROP, MOVE, INVENTORY or QUIT" << endl;
      cin.getline(input, 100);
      for(int i = 0; i < strlen(input); i++)
      {
        input[i] = toupper(input[i]);
      }
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
      if(strcmp(input, "INVENTORY") == 0)
      {
        printInventory(inventory);
      }
      if(strcmp(input, "QUIT") == 0)
      {
        running = false;
      }
    } while (strcmp(input, "PICK UP") != 0 && strcmp(input, "DROP") != 0 && strcmp(input, "MOVE") != 0 && strcmp(input, "INVENTORY") != 0 && strcmp(input, "QUIT"));
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
  for(int i = 0; i < strlen(itemName); i++) //function for this?
  {
    itemName[i] = toupper(itemName[i]);
  }
  int index = currentRoom->containsItem(itemName);
  if(index > -1)
  {
    inventory.push_back(currentRoom->getItems()[index]);
    currentRoom->removeItem(index);
    cout << "item picked up" << endl;
    return;
  }
  cout << "this item does not exist" << endl;
}

//removes item from player inventory, adds it to the current room
void dropItem(Room* currentRoom, vector<Room::Item*>& inventory)
{
  char itemName[100];
  cout << "enter the name of the item you want to drop" << endl;
  cin.getline(itemName, 100);
  int index = inventoryContains(inventory, itemName);
  if( index > -1)
  {
    inventory.erase(inventory.begin() + index);
    currentRoom->addItem(inventory[index]);
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
      currentRoom->printInfo();
    }
  }
}

//if contains item, returns its index. if not, returns -1
int inventoryContains(vector<Room::Item*>& inventory, const char* itemName)
{
  for(int i = 0; i < inventory.size(); i++)
  {
    if(strcmp(inventory[i]->name, itemName) == 0)
    {
      return i;
    }
  }
  return -1;
}

void printInventory(vector<Room::Item*> inventory)
{
  if(inventory.size() >  0)
  {
    cout << "Your inventory contains: ";
    for(int i = 0; i < inventory.size(); i++)
    {
      if(i == inventory.size() - 1)
      {
        cout << inventory[i]->name;
      }
      else
      {
        cout << inventory[i]->name << ", ";
      }
    }
    cout << endl;
  }
  else
  {
    cout << "there are no items in your inventory" << endl;
  }
}

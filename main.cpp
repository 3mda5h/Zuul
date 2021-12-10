#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <cstring>

using namespace std;

void pickUpItem(Room* currentRoom, vector<Item*>& inventory);
void dropItem(Room* currentRoom, vector<Item*>& inventory);
void move();

int main() 
{
  vector<Item*> inventory;
  int index;
  Room* currentRoom = new Room();
  bool running = true;
  char input[100];
 
  //Room setup
  Room* oneTwenty = new Room(); 
  Room* oneHall = new Room();
  oneTwenty->setExit("north", oneHall); //idk if it's actually north
  Room::Item* computer = new Room::Item();
  oneTwenty->addItem(computer);
  oneTwenty->setDescription("You are haning out in room 1-20. You are 100% doing C++ programming and not bio homework.");
  currentRoom = oneTwenty;
  
  do
  {
    currentRoom->printDescription();
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
        move();
      }
      if(strcmp(input, "QUIT") == 0)
      {
        running = false;
      }
    }
  } while(running == true);
} 

//adds item to player inventory, removes it from the room 
void pickUpItem(Room* currentRoom, vector<Item*>& inventory)
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
void dropItem(Room* currentRoom, vector<Item*>& inventory)
{
  char itemName[100];
  cout << "enter the name of the item you want to drop" << endl;
  cin.getline(itemName, 100);
  for(int i = 0; i < inventory.size(); i++)
  {
    if(strcmp(inventory[i]->name, itemName) == 0)
    {
    inventory.erase(inventory.begin() + index);
    currentRoom->addItem(inventory[index]);
    return;
    }
  }
  cout << "this item is not in your inventory" << endl;
}

//changes current room based on exit chosen
void move()
{
  char input[100];
  cout << "which exit?" << endl;
  cin.getline(input, 100);
}

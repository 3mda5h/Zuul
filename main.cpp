#include <iostream>
#include "room.cpp"
#include <vector>
#include <map>
#include <cstring>

using namespace std;

void pickUpItem(Room* currentRoom, vector<Item*>& inventory);

int main() 
{
  //vector<Room*> rooms; - do i need this?
  vector<Item*> inventory;
  Room* cafeteria = new Room(); //probably spelled wrong fix later
  Room* currentRoom = new Room();
  currentRoom = cafeteria;
  bool running = true;
  char input[100];
  //set up rooms here I think?
  do
  {
    cout << "enter PICK UP, DROP, MOVE, PRINT, or QUIT" << endl;
    cin.getline(input, 100);
    {
      if(strcmp(input, "PICK UP") == 0)
      {
        pickUpItem(currentRoom, inventory);
      }
      if(strcmp(input, "DROP") == 0)
      {

      }
      if(strcmp(input, "MOVE") == 0)
      {

      }
      if(strcmp(input, "PRINT") == 0)
      {

      }
      if(strcmp(input, "QUIT") == 0)
      {
        running = false;
      }
    }
  } while(running == true);
} 

void pickUpItem(Room* currentRoom, vector<Item*>& inventory)
{
  bool itemExists = false;
  char itemName[100];
  cout << "enter name of item you want to pick up" << endl;
  for(int i = 0; i < currentRoom->getItems().size())
  {
    if(strcmp(currentRoom->getItems()[i]->name, itemName) == 0)
    {
      itemExists = true;
      inventory.push_back(currentRoom->getItems()[i]);
      return;
    }
  }
  if(itemExists == false)
  {
    cout << "there is no " << itemName << "in this room" << endl;
  }
}
//zuul - text-based adventure game, explore rooms and pick up + drop items 
//ways to win:   1) get money from khall then donate it in e3,   2) pick up the banana peel in the cafeteria and throw it away in the lower commons,   3) get library book from g4 and return to the media center, or   4) return basket ball in two hall to the gym 
//Emily MacPherson, 12/19/21
#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <cstring>
#include <iterator>

using namespace std;

Room::Item* newItem(const char* name);
void pickUpItem(Room* currentRoom, vector<Room::Item*>& inventory);
void dropItem(Room* currentRoom, vector<Room::Item*>& inventory);
void move(Room*& currentRoom);
int inventoryContains(vector<Room::Item*>& inventory, const char* itemName);
void printInventory(vector<Room::Item*> inventory);
void upperCase(char*& input);

int main() 
{
  vector<Room::Item*> inventory;
  Room* currentRoom;
  int inventoryIndex;
  bool running = true;
  char input[100];
 
  //create rooms
  Room* oneTwenty = new Room("You are in room 1-20. You are 100% doing C++ programming and not bio homework.");
  Room* oneHall = new Room("You are in one hall, an endless sea of humans.");
  Room* oneNine = new Room("You have entered IB biology O_O");
  Room* kHall = new Room("You are at the K hall-one hall intersection. Hey wait... is that a dollar on the ground?");
  Room* eThree = new Room("You are in Room E3, 3rd period History. Is that a donation box for the winter holiday drive? :O");
  Room* fHall = new Room("You are at the F hall-one hall intersection. Nothing much going on here.");
  Room* cafeteria = new Room("You are in the cafeteria. Is that a banana peel you just stepped on?");
  Room* lowerCommons = new Room("You are in the lower commons. Hey, there's a trash can.");
  Room* gHall = new Room("You are at the G hall-one hall intersection.");
  Room* gSix = new Room("Bienvenido! You are in Spanish class. Did you leave your library book in here? :o");
  Room* mediaCenter = new Room("You are in the media center.");
  Room* jHall = new Room("You are in J hall.");
  Room* threeEleven = new Room("You are in room 3-11, health class.");
  Room* gym = new Room("You are in the gym. A bunch of loud tall people are playing basketball.");
  Room* twoHall = new Room("You are in two hall.");
  
  //set exits
  oneTwenty->setExit("WEST", oneHall); 
  oneHall->setExit("EAST", oneTwenty);
  oneHall->setExit("NORTH", kHall);
  oneHall->setExit("SOUTH", fHall);
  oneHall->setExit("WEST", cafeteria);
  cafeteria->setExit("NORTH", lowerCommons);
  cafeteria->setExit("EAST", oneHall);
  cafeteria->setExit("WEST", twoHall);
  lowerCommons->setExit("SOUTH", cafeteria);
  twoHall->setExit("WEST", jHall);
  twoHall->setExit("EAST", cafeteria);
  jHall->setExit("EAST", twoHall);
  jHall->setExit("NORTH", gym);
  jHall->setExit("WEST", threeEleven);
  gym->setExit("SOUTH", jHall);
  threeEleven->setExit("EAST", jHall);
  kHall->setExit("SOUTH", oneHall);
  kHall->setExit("EAST", oneNine);
  kHall->setExit("NORTH", mediaCenter);
  mediaCenter->setExit("SOUTH", kHall);
  fHall->setExit("NORTH", oneHall);
  fHall->setExit("EAST", eThree);
  fHall->setExit("SOUTH", gHall);
  eThree->setExit("WEST", fHall);
  gHall->setExit("NORTH", fHall);
  gHall->setExit("EAST", gSix);
  gSix->setExit("WEST", gHall);

  //set items
  oneTwenty->addItem(newItem("COMPUTER"));
  kHall->addItem(newItem("DOLLAR"));
  oneNine->addItem(newItem("SUFFERING"));
  cafeteria->addItem(newItem("BANANA PEEL"));
  gSix->addItem(newItem("BOOK"));
  twoHall->addItem(newItem("BASKETBALL"));
  
  currentRoom = oneTwenty;
  currentRoom->printInfo();
  do
  {
    //win & lose conditions hehehehe
    if(currentRoom != oneTwenty && inventoryContains(inventory, "COMPUTER") > -1)
    {
      cout << "Wait... you just stole a computer from 1-20 D:< That's mean. You lose." << endl;
      return(0);
    }
    if(currentRoom == oneNine)
    {
      cout << "There is no escape from IB bio. You are trapped until the end of time. You lose." << endl;
      return(0);
    }
    if(currentRoom == threeEleven)
    {
      cout << "You instantly run away screaming. You do not like health class." << endl;
      currentRoom = jHall;
      currentRoom->printInfo();
    }
    if(eThree->containsItem("DOLLAR") > -1)
    {
      cout << "You donated to the holiday drive! You win :D";
      return(0);
    }
    if(mediaCenter->containsItem("BOOK") > -1)
    {
      cout << "You returned your library book! You win :D" << endl;
      return(0);
    }
    if(lowerCommons->containsItem("BANANA PEEL") > -1)
    {
      cout << "Yay, you threw away the banana peel. You win :D" << endl;
      return(0);
    }
    if(gym->containsItem("BASKETBALL") > -1)
    {
      cout << "You returned the basket ball to the gym. You win :D" << endl;
      return(0);
    }
    do
    {
      cout << "Type PICK UP, DROP, MOVE, INVENTORY or QUIT" << endl;
      cin.getline(input, 100);
      for(int i = 0; i < strlen(input); i++) //for case sensitivity 
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
    } while (strcmp(input, "PICK UP") != 0 && strcmp(input, "DROP") != 0 && strcmp(input, "MOVE") != 0 && strcmp(input, "INVENTORY") != 0 && strcmp(input, "QUIT")); //keep prompting user until valid command is inputed
  } while(running == true); 
} 

//creates a new item with passed-in name
Room::Item* newItem(const char* itemName)
{
  Room::Item* item = new Room::Item();
  strcpy(item->name, itemName);
  return item;
}

//adds item to player inventory, removes it from the room 
void pickUpItem(Room* currentRoom, vector<Room::Item*>& inventory)
{
  if(currentRoom->getItems().size() == 0) //if room has no items
  {
    cout << "There's nothing to pick up in this room." << endl;
    return;
  }
  char itemName[100];
  cout << "Which item?" << endl;
  cin.getline(itemName, 100);
  for(int i = 0; i < strlen(itemName); i++)
  {
    itemName[i] = toupper(itemName[i]);
  }
  int index = currentRoom->containsItem(itemName);
  if(index > -1)
  {
    inventory.push_back(currentRoom->getItems()[index]);
    currentRoom->removeItem(index);
    cout << "Item picked up." << endl;
    return;
  }
  cout << "This item does not exist D:" << endl;
}

//removes item from player inventory, adds it to the current room
void dropItem(Room* currentRoom, vector<Room::Item*>& inventory)
{
  if(inventory.size() == 0) //if inventory is empty
  {
    cout << "There's nothing in your inventory to drop." << endl;
    return;
  }
  char itemName[100];
  cout << "Which item?" << endl;
  cin.getline(itemName, 100);
  for(int i = 0; i < strlen(itemName); i++) 
  {
    itemName[i] = toupper(itemName[i]);
  }
  int index = inventoryContains(inventory, itemName);
  if(index > -1)
  {
    Room::Item* item = inventory[index];
    inventory.erase(inventory.begin() + index);
    currentRoom->addItem(item);
    cout << "Item dropped." << endl;
    return;
  }
  cout << "This item is not in your inventory D:" << endl;
}

//changes current room based on exit chosen
void move(Room*& currentRoom)
{
  char input[100];
  cout << "Which exit?" << endl;
  cin.getline(input, 100);
  for(int i = 0; i < strlen(input); i++) 
  {
    input[i] = toupper(input[i]);
  }
  map<const char*, Room*> exits;
  exits = currentRoom->roomMap;
  map<const char*, Room*>::iterator it;
  for(it = exits.begin(); it != exits.end(); it++)
  {
    char c[100];
    strcpy(c, it->first); //convert const char to char[100] so it can compare to input
    if(strcmp(c, input) == 0)
    {
      currentRoom = it->second;
      currentRoom->printInfo();
      return;
    }
  }
  cout << "This exit doesn't exist D:" << endl;
}

//if inventory contains item, returns its index. if not, returns -1
int inventoryContains(vector<Room::Item*>& inventory, const char* itemName)
{
  char temp[100];
  strcpy(temp, itemName); //convert const char to char array so it doesn't get angry
  for(int i = 0; i < inventory.size(); i++)
  {
    if(strcmp(inventory[i]->name, temp) == 0)
    {
      return i;
    }
  }
  return -1;
}

//prints out all items currently in player inventory
void printInventory(vector<Room::Item*> inventory)
{
  if(inventory.size() >  0)
  {
    cout << "Your inventory contains: ";
    for(int i = 0; i < inventory.size(); i++)
    {
      if(i == inventory.size() - 1) //last item no comma heh heh
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
    cout << "There are no items in your inventory." << endl;
  }
}

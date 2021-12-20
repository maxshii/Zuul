/*
 * This program will allow the user to play a text-based adventure game.
 * Author: Max Shi
 * Date: 12/14/2021
 */

#include <iostream>
#include <iterator>
#include <cstring>

#include "item.h"
#include "room.h"

using namespace::std;

void setRoom(Room **room, char direction);
void pickUp(Room *room, vector<Item> &inventory, char itemName[]);
void putDown(Room *room, vector<Item> &inventory, char itemName[]);

int main() {
  

  vector<Item> inventory;
  Room *currentRoom = &r1;

  while(true)
  {
    cout << currentRoom->description << endl;

    vector<Item>::iterator it;
      
    cout << "Items in room: ";
    for(it = currentRoom->items.begin(); it < currentRoom->items.end(); ++it)
    {
       cout << it->name << " ";
    }
    cout << endl;

    cout << "Held items: ";
    for(it = inventory.begin(); it < inventory.end(); ++it)
    {
       cout << it->name << " ";
    }
    cout << endl;

    
    cout << "\nEnter a command(GO, PICKUP, PUTDOWN, QUIT)\n";

    char input[80];
    cin.getline(input, 80);   

    if(strcmp(input, "GO") == 0)
    {
      cout << "Choose a direction to go:\n";
 
      for(pair<char, Room*> element : currentRoom->exits)
      {
        cout << element.first << "\n";
      }
      char direction;
      cin >> direction;
      cin.ignore();  
      setRoom(&currentRoom, direction);
    }
    else if(strcmp(input, "PICKUP") == 0)
    {
      cout << "Enter item to pick up: ";
      cin.getline(input, 80); 
      pickUp(currentRoom, inventory, input);
    }
    else if(strcmp(input, "DROP") == 0)
    {
      cout << "Enter item to put down: ";
      cin.getline(input, 80); 
      putDown(currentRoom, inventory, input);
    }
    else if(strcmp(input, "QUIT") == 0)
    {
      break;
    }
    

  }
} 

void setRoom(Room **room, char direction)
{

  for(pair<char, Room*> element : (**room).exits)
  {
    if(element.first == direction)
    {
      *room = (element.second);
    }   
  } 
}

void pickUp(Room *room, vector<Item> &inventory, char itemName[])
{
  
  vector<Item>::iterator it;
    
  for(it = room->items.begin(); it < room->items.end(); ++it)
  {
    if(strcmp(it->name, itemName) == 0)
    {
      cout << "Picked up " << it->name <<endl;
      inventory.push_back(*it);
      room->items.erase(it);
    }
  }
}

void putDown(Room *room, vector<Item> &inventory, char itemName[])
{
  vector<Item>::iterator it;
    
  for(it = inventory.begin(); it < inventory.end(); ++it)
  {
    if(strcmp(it->name, itemName) == 0)
    {
      cout << "Put down " << it->name <<endl;
      room->items.push_back(*it);
      inventory.erase(it);
    }
  }
}

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

  char d1[20] = "This is a room.";
  char d2[20] = "Poop";
  char d3[20] = "Toilet";
  Room room(d1);
  Item poop(d2);
  Item toilet(d3);

  char c1[20] = "This is a room2.";
  char c2[20] = "Poger";
  //char c3[20] = "Toilet";
  Room room2(c1);
  Item pogger(c2);

  inventory.push_back(pogger);

  room.exits.insert(pair<char, Room*>('N', &room2));

  room.items.push_back(poop);
  room.items.push_back(toilet);

  Room *currentRoom = &room;

  while(true)
  {
    cout << currentRoom->description << endl;
    break;
    vector<Item>::iterator it;
      
    for(it = room.items.begin(); it < room.items.end(); ++it)
    {
      cout << "before" << it->name << endl;
    }
    for(it = inventory.begin(); it < inventory.end(); ++it)
    {
      cout << "in" << it->name << endl;
    }
    pickUp(currentRoom, inventory, d2);

      
    for(it = room.items.begin(); it < room.items.end(); ++it)
    {
      cout << "after" << it->name << endl;
    }

    for(it = inventory.begin(); it < inventory.end(); ++it)
    {
      cout << "in" << it->name << endl;
    }
    

    //for(it = *currentRoom.items.begin(); it < currentRoom.items.end(); ++it)
    //{
    //  cout << it->name << endl;
  // }

    

    //cout << room.items.begin()->name << "\n";

    
    map<char, Room>::iterator it1;
    //for(it1 = room.exits.begin(); it1 != room.exits.end(); ++it1)
    //{
      //cout << it1->first << endl;
    //}

  }
} 

void setRoom(Room **room, char direction)
{

  for(pair<char, Room*> element : (**room).exits)
  {
    if(element.first == direction)
    {
      //cout << (element.second);
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
      cout << "\ndetecteditem" << it->name <<endl;
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
      cout << "\ndetecteditem" << it->name <<endl;
      room->items.push_back(*it);
      inventory.erase(it);
    }
  }
}

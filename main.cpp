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

void setRoom(Room &room, char direction);

int main() {
  char d1[20] = "This is a room.";
  char d2[20] = "Poop";
  char d3[20] = "Toilet";
  Room room(d1);
  Item poop(d2);
  Item toilet(d3);

  char c1[20] = "This is a room2.";
  char c2[20] = "Pogger";
  //char c3[20] = "Toilet";
  Room room2(c1);
  Item pogger(c2);

  

  room.exits.insert(pair<char, Room>('N', room));

  room.items.push_back(poop);
  room.items.push_back(toilet);

  Room currentRoom = room;
  strcpy(currentRoom.description, "This is new desciripton");

  cout << "current" << currentRoom.description << endl;
  cout << "room" << room.description << endl;


  vector<Item>::iterator it;
    
  for(it = room.items.begin(); it < room.items.end(); ++it)
  {
    cout << it->name << endl;
  }

  for(it = currentRoom.items.begin(); it < currentRoom.items.end(); ++it)
  {
    cout << it->name << endl;
  }

  

  //cout << room.items.begin()->name << "\n";

  
  map<char, Room>::iterator it1;
  for(it1 = room.exits.begin(); it1 != room.exits.end(); ++it1)
  {
    //cout << it1->first << endl;
  }


} 

void setRoom(Room &room, char direction)
{
  map<char, Room>::iterator it1;
  for(it1 = room.exits.begin(); it1 != room.exits.end(); ++it1)
  {
    if(it1->first == direction)
    {
      room = it1->second;
    }
  }
  
}
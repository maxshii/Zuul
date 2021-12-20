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

void setExit(Room &roomToLeave, char direction, Room *roomToEnter);
void setItem(Room &room, Item item);
void changeRoom(Room **room, char direction);
void pickUp(Room *room, vector<Item> &inventory, char itemName[]);
void putDown(Room *room, vector<Item> &inventory, char itemName[]);

int main() {
  //create the rooms (Zuul locations and items taken from my Java Zuul assignment)
  Room onetwenty((char*)"You are currently in the 1-20 lab.  All the cool people are hanging out here. Pick up \"WIN\" to win");
  Room outside = ((char*)"You are outside the main entrance of Sunset");
  Room mainoffice((char*)"You are in the main office");
  Room mainhall((char*)"You are in main hall");
  Room onehall((char*)"You are in one hall");
  Room cafeteria((char*)"You are in the cafeteria. It smells very yumyum.");
  Room twohall((char*)"You are in two hall");
  Room gym((char*)"You are in the gym. You start chasing balls");
  Room threehall((char*)"You are in three hall");
  Room ahall((char*)"You are in A hall. All the unpog classes are here");
  Room hhall((char*)"You are in H hall. Math is taught here");
  Room ghall((char*)"You are in G hall. It smells like tacos in here");
  Room bathroom((char*)"You are in the bathroom. It smells like mangos");
  Room gamercave((char*)"You are in the Gamer Cave. All the gamers are hanging out here");
  Room dungeon((char*)"You are in the dungeon. It is dank and musty.");
		
  //set the exits to the rooms
  setExit(onetwenty, 'N', &onehall);
  
  setExit(outside, 'S', &mainoffice);

  setExit(mainoffice, 'N', &outside);
  setExit(mainoffice, 'W', &mainhall);

  setExit(mainhall, 'E', &mainoffice);
  setExit(mainhall, 'W', &onehall);

  setExit(onehall, 'E', &mainhall);
  setExit(onehall, 'W', &cafeteria);
  setExit(onehall, 'S', &onetwenty);

  setExit(cafeteria, 'E', &onehall);
  setExit(cafeteria, 'W', &twohall);

  setExit(twohall, 'N', &ahall);
  setExit(twohall, 'E', &cafeteria);
  setExit(twohall, 'W', &gym);
  setExit(twohall, 'S', &hhall);

  setExit(gym, 'E', &twohall);
  setExit(gym, 'W', &threehall);

  setExit(threehall, 'E', &gym);
  setExit(threehall, 'S', &bathroom);
  setExit(threehall, 'W', &dungeon);

  setExit(ahall, 'S', &twohall);

  setExit(hhall, 'N', &twohall);

  setExit(bathroom, 'N', &threehall);

  setExit(gamercave, 'E', &dungeon);

  setExit(dungeon, 'E', &threehall);
  setExit(dungeon, 'W', &gamercave);

  //set items of rooms
  Item i1((char*)"WIN");
  setItem(onetwenty, i1);
  Item i0((char*)"MR.GALBRAITH");
  setItem(onetwenty, i0);
  
  Item i2((char*)"BALL");
  Item i3((char*)"SOCK");
  setItem(gym, i2);
  setItem(gym, i3);

  Item i4((char*)"TOILET");
  setItem(bathroom, i4);

  Item i5((char*)"FOOD");
  setItem(cafeteria, i5);

  
  vector<Item> inventory; 
  Room *currentRoom = &onetwenty; //set start point of game

  //loop until game is won or quit     
  bool exit = false;
  while(exit == false)
  {
    cout << currentRoom->description << endl; 
    
    //print items in room and inventory
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

    //enter commands
    cout << "\nEnter a command(GO, PICKUP, DROP, QUIT)\n";
    char input[80];
    cin.getline(input, 80);   

    if(strcmp(input, "GO") == 0) //change room based on direction
    {
      cout << "Choose a direction to go:\n";

      for(pair<char, Room*> element : currentRoom->exits)
      {
        cout << element.first << "\n";
      }

      char direction = '\n';
      cin >> direction;
      cin.ignore();  
      changeRoom(&currentRoom, direction);
    }
    else if(strcmp(input, "PICKUP") == 0) //pickup item
    {
      cout << "Enter item to pick up: ";
      cin.getline(input, 80); 
      pickUp(currentRoom, inventory, input);
    }
    else if(strcmp(input, "DROP") == 0) //drop item
    {
      cout << "Enter item to put down: ";
      cin.getline(input, 80); 
      putDown(currentRoom, inventory, input);
    }
    else if(strcmp(input, "QUIT") == 0) //quit game
    {
      cout << "You quit :(\n";
      break;
    }
    
    for(it = inventory.begin(); it < inventory.end(); ++it)
    {
      if(strcmp(it->name, "WIN") == 0)
      {
        cout << "You won!\n";
        exit = true;
      }
    }
  }
} 

//adds a direction and a room pointer to the Room's map of exits
void setExit(Room &roomToLeave, char direction, Room *roomToEnter)
{
  roomToLeave.exits.insert({direction, roomToEnter});
}

//puts and item into a room
void setItem(Room &room, Item item)
{
  room.items.push_back(item);
}

//changes the current room to the room in the chosen direction
void changeRoom(Room **room, char direction)
{
  for(pair<char, Room*> element : (**room).exits)
  {
    if(element.first == direction)
    {
      *room = (element.second); //makes room point to new room
    }   
  } 
}

//puts the chosen item into the player's inventory and removes it from the room
void pickUp(Room *room, vector<Item> &inventory, char itemName[])
{
  
  vector<Item>::iterator it;
  for(it = room->items.begin(); it < room->items.end(); ++it)
  {
    if(strcmp(it->name, itemName) == 0)
    {
      cout << "Picked up " << it->name <<endl;
      inventory.push_back(*it); //add to inventory
      room->items.erase(it); //remove from room
    }
  }
}

//puts the chosen item into the room and removes it from the player's inventory
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

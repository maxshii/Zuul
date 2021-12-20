/*
 * This file contains the methods for Room.
 * Author: Max Shi
 * Date: 12/14/2021
 */
 
#include "room.h"
#include <cstring>
#include <iostream>
using namespace::std;

Room::Room(char newDescription[200])
{
  strcpy(description, newDescription);
  vector<Item> items;
  map<char, Room*> exits;
}
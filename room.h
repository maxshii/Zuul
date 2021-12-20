/*
 * This class represents a location in Zuul. A room consists of a description of the 
 * room, a vector holding items in the room, and a map with the exits. The exits will
 * have a  direction and the room that is in that direction.
 * Author: Max Shi
 * Date: 12/14/2021
 */

#include "item.h"
#include <map>
#include <vector>

using namespace::std;

class Room
{
  public:
    Room(char newDescription[200]);
    char description[200];
    vector<Item> items;
    map<char, Room*> exits; //map with key values that are directions represented by a character and mapped values of Room pointers
};
/*
 * This file contains the methods for Item.
 * Author: Max Shi
 * Date: 12/14/2021
 */
 
#include "item.h"
#include <cstring>

Item::Item(char newName[80])
{
  strcpy(name, newName);
}
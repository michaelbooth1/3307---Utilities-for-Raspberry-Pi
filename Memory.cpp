/*
Author: Michael Booth
Date: October 4th, 2018
Description: Retrieves memory information 
*/

#include "Memory.h"
#include <iostream>
#include <sys/sysinfo.h>
using namespace std;

//Constructor gets information from system
Memory::Memory(){
    sysinfo(&mem);
}

//Getter method for total ram
long Memory::getTotalRam(){
    return mem.totalram;
}

//Getter method for free ram
long Memory::getFreeRam(){
    return mem.freeram;
}
//Getter method for shared ram
long Memory::getSharedRam(){
    return mem.sharedram;
}

//Getter method for buffer ram
long Memory::getBufferRam(){
    return mem.bufferram;
}

//returns all information from class in a string
string Memory::toString(){
    returnVal = "Total RAM: ";
    returnVal.append(to_string(this->getTotalRam()) + "\n");
    returnVal.append("Free RAM: ");
    returnVal.append(to_string(this->getFreeRam()) + "\n");
    returnVal.append("Shared RAM: ");
    returnVal.append(to_string(this->getSharedRam()) + "\n");
    returnVal.append("Get Buffer RAM: ");
    returnVal.append(to_string(this->getBufferRam()) + "\n");
    return returnVal;
}
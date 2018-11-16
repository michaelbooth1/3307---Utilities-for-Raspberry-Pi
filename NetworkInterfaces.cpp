/*
Author: Michael Booth
Date: October 4th, 2018
Description: creates object to hold network interface information
*/

#include "NetworkInterfaces.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor initializes variables that are passed in
NetworkInterfaces::NetworkInterfaces(string name, string adr){
    interfaceName = name;
    MacAdr = adr;
}

//Getter method for name
string NetworkInterfaces::getName(){
    return interfaceName;
}

//Getter method for MAC address
string NetworkInterfaces::getMacAddress(){
    return MacAdr;
}

//Returns string with name and MAC address
string NetworkInterfaces::toString(){
    returnVal = "Name: ";
    returnVal.append(this->getName());
    returnVal.append("  MAC Address: ");
    returnVal.append(this->getMacAddress());
    return returnVal;
}





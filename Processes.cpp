/*
Author: Michael Booth
Date: October 4th, 2018
Description: Object to hold information about system processes
*/
#include "Processes.h"
#include <iostream>
#include <string> 
using namespace std;

//Constructor initializes variables from passed in values
Processes::Processes(string procName, string oUID, string procState, int ID, int parID){
    name = procName;
    ownerUID = oUID;
    state = procState;
    procID = ID;
    parentProcID = parID;
}

//Getter method for name
string Processes::getName(){
    return name;
}

//Getter method for owner UID
string Processes::getOwnerUID(){
    return ownerUID;
}

//Getter method for state
string Processes::getState(){
    return state;
}

//Getter method for processes ID
int Processes::getProcID(){
    return procID;
}

//Getter method for processes parent ID
int Processes::getParentProcID(){
    return parentProcID;
}

//Returns string with all object information
string Processes::toString(){
    returnVal = "Proccess ID: ";
    returnVal.append(to_string(this->getProcID()) + "\n");
    returnVal.append("Name: ");
    returnVal.append(this->getName() + "\n");
    returnVal.append("Owner UID: ");
    returnVal.append(this->getOwnerUID() + "\n");
    returnVal.append("Parent Process ID: ");
    returnVal.append(to_string(this->getParentProcID()) + "\n");
    returnVal.append("State: ");
    returnVal.append(this->getState() + "\n");
    return returnVal;
}


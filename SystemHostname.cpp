/*
Author: Michael Booth
Date: October 4th, 2018
Description: Retrives information about system
*/
#include "SystemHostname.h"
#include <iostream>
#include <unistd.h>
using namespace std;

//Constructor gets host information from system
SystemHostname::SystemHostname(){
    gethostname(hostname, size);
}

//Getter method for hostname
string SystemHostname::getHostnameVar(){
    return hostname;
};

//Returns string with hostname
string SystemHostname::toString(){
    returnValue = "Hostname: ";
    returnValue.append(hostname); 
    return (returnValue);
};


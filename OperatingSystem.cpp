/*
Author: Michael Booth
Date: October 4th, 2018
Description: Retrieves information about operating system
*/
#include "OperatingSystem.h"
#include <iostream>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <math.h>   
using namespace std;

//Constructor initializes variables from systems call
OperatingSystem::OperatingSystem(){
    uname(&osData);
    sysinfo(&uptime);
}

//Getter method for OS name
string OperatingSystem::getOSName(){
    return osData.sysname;
}

//Getter method for OS release
string OperatingSystem::getRelease(){
    return osData.release;
}

//Getter method for OS version
string OperatingSystem::getVersion(){
    return osData.version;
}

//Getter method for OS machine data
string OperatingSystem::getMachineData(){
    return osData.machine;
}

//Getter method for OS uptime
string OperatingSystem::getUptime(){
    seconds = uptime.uptime;
    day = floor(seconds/86400);
    hour = floor((seconds - day*86400)/3600);
    min = floor((seconds - day*86400 - hour*3600)/60);
    sec = seconds - day*86400 - hour*3600 - min * 60;
    return uptime_s = to_string(day) + ":" + to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
}

//Returns string of all OS information
string OperatingSystem::toString(){
    returnVal = "OS Name: ";
    returnVal.append(this->getOSName() + "\n");
    returnVal.append("Release: ");
    returnVal.append(this->getRelease() + "\n");
    returnVal.append("Version: ");
    returnVal.append(this->getVersion() + "\n");
    returnVal.append("Machine data: ");
    returnVal.append(this->getMachineData() + "\n");
    returnVal.append("Uptime: ");
    returnVal.append(this->getUptime() + "\n");
    return returnVal;
}



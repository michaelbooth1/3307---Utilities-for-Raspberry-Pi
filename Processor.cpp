/*
Author: Michael Booth
Date: October 4th, 2018
Description: Retrives information about processor
*/
#include "Processor.h"
#include <iostream>
#include <fstream>
#include <sys/sysinfo.h>
#include <string>
using namespace std;

//Constructor parses cpu info for relevant information
Processor::Processor(){
    ifstream output("/proc/cpuinfo");
    while(getline(output, line)){
        if(counter == 1 || counter == 4 || counter == 6){
            pos = line.find(":");
            switch(counter){
                case 1:
                    vendor = line.substr(pos + 2);
                    break;
                case 4:
                    modelName = line.substr(pos + 2);
                    break;
                case 6:
                    clockSpeed = line.substr(pos + 2);
                    break;
            }
        }
        counter += 1; 
    }
    output.close();

    sysinfo(&loadAvg);
}

//Getter method for vendor
string Processor::getVendor(){
    return vendor;
}

//Getter method for model name
string Processor::getModelName(){
    return modelName;
}

//Getter method for clock speed
string Processor::getClockSpeed(){
    return clockSpeed;
}

//Getter method for one minute load
long Processor::getOneMinuteLoad(){
    return loadAvg.loads[0];
}

//Getter method for five minute load
long Processor::getFiveMinuteLoad(){
    return loadAvg.loads[1];
}

//Getter method for fifteen minute load
long Processor::getFifteenMinuteLoad(){
    return loadAvg.loads[2];
}

//Returns string with all information formatted
string Processor::toString(){
    returnVal = "Vendor: ";
    returnVal.append(this->getVendor() + "\n");
    returnVal.append("Model Name: ");
    returnVal.append(this->getModelName() + "\n");
    returnVal.append("Clock Speed (MHz): ");
    returnVal.append(this->getClockSpeed() + "\n");
    returnVal.append("One Minute Load: ");
    returnVal.append(to_string(this->getOneMinuteLoad()) + "\n");
    returnVal.append("Five Minute Load: ");
    returnVal.append(to_string(this->getFiveMinuteLoad()) + "\n");
    returnVal.append("Fifteen Minute Load: ");
    returnVal.append(to_string(this->getFifteenMinuteLoad()) + "\n");
    return returnVal;
}
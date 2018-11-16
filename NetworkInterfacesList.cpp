/*
Author: Michael Booth
Date: October 4th, 2018
Description: creates a list of network interface objects
*/

#include "NetworkInterfacesList.h"
#include "NetworkInterfaces.h"
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <fstream>
using namespace std;

//Constructor goes through directory and creates network interface objects
NetworkInterfacesList::NetworkInterfacesList(){
    dir = opendir("/sys/class/net");
    while(entry = readdir(dir)){
        if(entry->d_name[0] != '.' && entry->d_name != ".."){
            folder.append(entry->d_name);
            folder.append("/address");
            ifstream output(folder);
            while(getline(output, line)){
                    NetworkInterfaces net = NetworkInterfaces(entry->d_name, line);
                    filenames.push_back(net);
            }
            output.close();     
        }
        folder = "/sys/class/net/";
    }
}

//Returns string with all network interfaces information
string NetworkInterfacesList::toString(){
    for(vector<NetworkInterfaces>::iterator i = filenames.begin(); i != filenames.end(); i++){
        returnVal.append(i->toString() + "\n");
    }
    return returnVal;
}


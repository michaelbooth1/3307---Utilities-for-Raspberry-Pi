/*
Author: Michael Booth
Date: October 4th, 2018
Description: Creates list of processes objects
*/
#include "Processes.h"
#include "ProcessesList.h"
#include <iostream>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <fstream>
#include <string> 
using namespace std;

//Constructor goes through directory to retrieve all processes
ProcessesList::ProcessesList(){
    dir = opendir("/proc/");
    while(entry = readdir(dir)){
        if(isdigit(entry->d_name[0])){
            folder.append(entry->d_name);
            folder.append("/status");
            ifstream output(folder);
            while(getline(output, line)){
                if(counter == 0 || counter == 2 || counter == 5 || counter == 6 || counter == 8){
                    pos = line.find(":");
                    switch(counter){
                        case 0:
                            name = line.substr(pos + 2);
                            break;
                        case 2:
                            state = line.substr(pos + 2);
                            break;
                        case 5:
                            procID = stoi(line.substr(pos + 2));
                            break;
                        case 6:
                            parentProcID = stoi(line.substr(pos + 2));
                            break;
                        case 8:
                            ownerUID  = line.substr(pos + 2);
                            break;
                    }
                }
                counter += 1;
            }
            Processes tempProc = Processes(name, ownerUID, state, procID, parentProcID);
            procList.push_back(tempProc);
            output.close();     
        }
        folder = "/proc/";
        counter = 0;
    }
}

//Returns string with all processes information
string ProcessesList::toString(){
    for(vector<Processes>::iterator i = procList.begin(); i != procList.end(); i++){
        returnVal.append(i->toString() + "\n");
    }
    return returnVal;
}

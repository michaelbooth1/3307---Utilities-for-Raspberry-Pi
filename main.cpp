/*
Author: Michael Booth
Date: October 4th, 2018
Description: User selects information to output from list of options
*/

#include <iostream>
#include "SystemHostname.h"
#include "OperatingSystem.h"
#include "Processor.h"
#include "Memory.h"
#include "NetworkInterfacesList.h"
#include "ProcessesList.h"

using namespace std;

int main(){
    int option = 0;                                    //Users choice
    string menu =   "\n" 
                    "Please enter a number \n"         //Menu with options 
                    "Option 1: System Hostname \n"
                    "Option 2: Operating System \n"
                    "Option 3: Processor \n"
                    "Option 4: Memory \n"
                    "Option 5: Network Interfaces \n"
                    "Option 6: Processes \n"
                    "Option 7: Exit \n";

    //Create objects for each class
    SystemHostname host;
    OperatingSystem os;
    Processor proc;
    Memory mem;
    NetworkInterfacesList net;
    ProcessesList procList;

    //Loop until user decides to exit
    while(option != 7){
        cout << menu << endl;
        cin >> option;
        cout << endl;
        switch(option){
            case 1:
                cout << host.toString() << endl;
                break;
            case 2:
                cout << os.toString() << endl;
                break;
            case 3:
                cout << proc.toString() << endl;
                break;
            case 4:
                cout << mem.toString() << endl;
                break;
            case 5:
                cout << net.toString() << endl;
                break;
            case 6:
                cout << procList.toString() << endl;
                break;
        }
    }
}
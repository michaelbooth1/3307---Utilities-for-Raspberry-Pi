#ifndef NetworkInterfacesList_h
#define NetworkInterfacesList_h
#include <sys/types.h>
#include <string>
#include <vector>
#include <dirent.h>
#include "NetworkInterfaces.h"

class NetworkInterfacesList{
    private:
        DIR *dir;
        struct dirent *entry;
        std::vector<NetworkInterfaces> filenames;
        std::string line, folder = "/sys/class/net/", returnVal = "";
    public:
        NetworkInterfacesList();
        std::string toString();
};


#endif
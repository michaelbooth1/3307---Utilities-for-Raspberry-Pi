#ifndef ProcessesList_h
#define ProcessesList_h
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string>
#include "Processes.h"

class ProcessesList{
    private:
        DIR *dir;
        struct dirent *entry;
        std::vector<Processes> procList;
        std::string line, folder = "/proc/", name, ownerUID, state, returnVal = "";
        int counter = 0, procID, parentProcID, pos;
    public:
        ProcessesList();
        std::string toString();

};

#endif
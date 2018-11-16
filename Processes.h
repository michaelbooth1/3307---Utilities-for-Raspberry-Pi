#ifndef Processes_h
#define Processes_h
#include <string>

class Processes{
    private:
        int procID, parentProcID;
        std::string name, ownerUID, state, returnVal = "";
    public:
        Processes(std::string procName, std::string oUID, std::string procState, int ID, int parID);
        std::string getName();
        std::string getOwnerUID();
        std::string getState();
        int getProcID();
        int getParentProcID();
        std::string toString();
};

#endif
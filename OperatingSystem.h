#ifndef OperatingSystem_h
#define OperatingSystem_h
#include <string>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

class OperatingSystem{
    private:
        struct utsname osData; 
        struct sysinfo uptime;
        char osName[32], release[32], version[32], machineData[32];
        std::string uptime_s, returnVal;
        long seconds;
        int day,hour,min,sec;
    public:
        OperatingSystem();
        std::string getOSName();
        std::string getRelease();
        std::string getVersion();
        std::string getMachineData();
        std::string getUptime();
        std::string toString();
};
#endif
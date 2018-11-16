#ifndef Memory_h
#define Memory_h
#include <string>
#include <sys/sysinfo.h>

class Memory{
    private:
        struct sysinfo mem;
        std::string returnVal;
    public:
        Memory();
        long getTotalRam();
        long getFreeRam();
        long getSharedRam();
        long getBufferRam();
        std::string toString();
};
#endif
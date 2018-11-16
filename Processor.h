#ifndef Processor_h
#define Processor_h
#include <string>
#include <sys/sysinfo.h>

class Processor{
    private:
        struct sysinfo loadAvg;
        std::string line, vendor, modelName, clockSpeed, returnVal;
        int counter = 0, pos;
        unsigned long averages[3];
    public:
        Processor();
        std::string getVendor();
        std::string getModelName();
        std::string getClockSpeed();
        long getOneMinuteLoad();
        long getFiveMinuteLoad();
        long getFifteenMinuteLoad();
        std::string toString();
};
#endif
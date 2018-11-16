#ifndef SystemHostname_h
#define SystemHostname_h
#include <string>

class SystemHostname{
    private:
        char hostname[32];
        int size = 32;
        std::string returnValue;
    public:
        SystemHostname();
        std::string getHostnameVar();
        std::string toString();
};

#endif
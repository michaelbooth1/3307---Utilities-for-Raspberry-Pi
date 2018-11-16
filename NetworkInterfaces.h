#ifndef NetWorkInterfaces_h
#define NetWorkInterfaces_h
#include <string>

class NetworkInterfaces{
    private:
        std::string interfaceName, MacAdr, returnVal;
    public:
        NetworkInterfaces(std::string name, std::string adr);
        std::string getName();
        std::string getMacAddress();
        std::string toString();
};
#endif
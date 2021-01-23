//
// Created by flow on 23/01/2021.
//

#ifndef B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_BODY_HPP
#define B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_BODY_HPP

#include "IMonitorDisplay.hpp"

namespace sysI
{
    class Body;
}

bool MyGKrellmTerminal(sysI::Body& body);
bool MyGKrellmGraphics(sysI::Body& body);

namespace sysI
{
    class Body : public IMonitorDisplay
    {
    public:
        enum DisplayLib {SFML, NCURSES};
        bool (*_prog[2])(sysI::Body&) = {&MyGKrellmGraphics, &MyGKrellmTerminal};

        Body(enum DisplayLib lib);
        ~Body() override;

        void setModuleMemory(Memory &mod) override;
        Memory *getModuleMemory() override;

        void setModuleUserName(UserName &mod) override;
        UserName *getModuleUserName() override;

        void setModuleHostName(HostName &mod) override;
        HostName *getModuleHostName() override;

        void setModuleCore(Core &mod) override;
        Core *getModuleCore() override;

        void setModuleTimeAndDate(TimeAndDate &mod) override;
        TimeAndDate *getModuleTimeAndDate() override;

        void setModuleOsInfo(OsInfo &mod) override;
        OsInfo *getModuleOsInfo() override;

        void setModuleNetwork(Network &mod) override;
        Network * getModuleNetwork() override;

        void InitModule(std::string lib);

        enum DisplayLib _Lib;

    private:
        Memory *_ModuleMemory;
        UserName *_ModuleUserName;
        HostName *_ModuleHostName;
        Core *_ModuleCore;
        OsInfo *_ModuleOsInfo;
        TimeAndDate *_ModuleTimeAndDate;
        Network *_ModuleNetwork;
    };
}


#endif //B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_BODY_HPP

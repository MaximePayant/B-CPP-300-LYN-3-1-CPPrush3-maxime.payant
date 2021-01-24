//
// Created by flow on 23/01/2021.
//

#ifndef B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_IMONITORDISPLAY_HPP
#define B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_IMONITORDISPLAY_HPP

#include "sysInfo.hpp"

namespace sysI {
    class IMonitorDisplay {
    public:
        virtual ~IMonitorDisplay() = default;

        virtual void setModuleMemory(Memory &mod) = 0;
        virtual Memory& getModuleMemory() = 0;

        virtual void setModuleUserName(UserName &mod) = 0;
        virtual UserName& getModuleUserName() = 0;

        virtual void setModuleHostName(HostName &mod) = 0;
        virtual HostName& getModuleHostName() = 0;

        virtual void setModuleCore(Core &mod) = 0;
        virtual Core& getModuleCore() = 0;

        virtual void setModuleTimeAndDate(TimeAndDate &mod) = 0;
        virtual TimeAndDate& getModuleTimeAndDate() = 0;

        virtual void setModuleOsInfo(OsInfo &mod) = 0;
        virtual OsInfo& getModuleOsInfo() = 0;

        virtual void setModuleNetwork(Network &mod) = 0;
        virtual Network& getModuleNetwork() = 0;
    };
}
#endif //B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_IMONITORDISPLAY_HPP

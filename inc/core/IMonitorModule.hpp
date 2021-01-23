//
// Created by flow on 23/01/2021.
//

#ifndef B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_IMONITORMODULE_HPP
#define B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_IMONITORMODULE_HPP

#include "sysInfo.hpp"

class IMonitorModule {
public:
    virtual ~IMonitorModule() = default;
    virtual void setActiveModule(bool value) = 0;
    virtual bool isEnable() = 0;
    virtual bool update() = 0;
};
#endif //B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_IMONITORMODULE_HPP

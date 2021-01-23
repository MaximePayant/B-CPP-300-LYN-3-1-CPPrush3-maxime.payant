//
// Created by flow on 23/01/2021.
//

#include "Body.hpp"

sysI::Body::Body(enum DisplayLib lib)
    : _Lib(lib)
{

}

sysI::Body::~Body() {}

void sysI::Body::InitModule(std::string lib) {
    (void)lib;
    _ModuleMemory = new Memory();
    _ModuleUserName = new UserName();
    _ModuleHostName = new HostName();
    _ModuleCore = new Core();
    _ModuleOsInfo = new OsInfo();
    _ModuleTimeAndDate = new TimeAndDate();
    _ModuleNetwork = new Network();
}

void sysI::Body::setModuleMemory(sysI::Memory &mod) {
    this->_ModuleMemory = &mod;
}

sysI::Memory *sysI::Body::getModuleMemory() {
    return this->_ModuleMemory;
}

void sysI::Body::setModuleUserName(sysI::UserName &mod) {
    this->_ModuleUserName = &mod;
}

sysI::UserName *sysI::Body::getModuleUserName() {
    return this->_ModuleUserName;
}

void sysI::Body::setModuleHostName(sysI::HostName &mod) {
    this->_ModuleHostName = &mod;
}

sysI::HostName *sysI::Body::getModuleHostName() {
    return this->_ModuleHostName;
}

void sysI::Body::setModuleCore(sysI::Core &mod) {
    this->_ModuleCore = &mod;
}

sysI::Core *sysI::Body::getModuleCore() {
    return this->_ModuleCore;
}

void sysI::Body::setModuleTimeAndDate(sysI::TimeAndDate &mod) {
    this->_ModuleTimeAndDate = &mod;
}

sysI::TimeAndDate *sysI::Body::getModuleTimeAndDate() {
    return this->_ModuleTimeAndDate;
}

void sysI::Body::setModuleOsInfo(sysI::OsInfo &mod) {
    this->_ModuleOsInfo = &mod;
}

sysI::OsInfo *sysI::Body::getModuleOsInfo() {
    return this->_ModuleOsInfo;
}

void sysI::Body::setModuleNetwork(sysI::Network &mod) {
    this->_ModuleNetwork = &mod;
}

sysI::Network *sysI::Body::getModuleNetwork() {
    return this->_ModuleNetwork;
}

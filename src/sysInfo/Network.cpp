//
// Created by flow on 23/01/2021.
//

#include "Network.hpp"

sysI::Network::Network()
    : _coState(checkConnection())
{

}

sysI::Network::~Network() {

}

std::string sysI::Network::getByteDown() const {
    return _byteDown;
}

std::string sysI::Network::getByteUp() const {
    return _byteUp;
}

std::string sysI::Network::getSpeed() const {
    return _Speed;
}

std::string sysI::Network::getName() const {
    return _Name;
}

bool sysI::Network::getCo() const {
    return _coState;
}

bool sysI::Network::checkConnection() {
    FILE *output;
    char val[100];
    std::string tmp;
    if(!(output = popen("/sbin/ip route","r"))) {
        return false;
    } fgets(val, 100, output);
    tmp.append(val);
    pclose(output);
    if (tmp.empty()) {
        tmp.clear();
        return false;
    } else {
        tmp.clear();
        return true;
    }
}

std::string refreshByteDown(std::string bytedown) {
    FILE *neo = new FILE;
    char buf[500] = { 0 };

    neo = popen("cat /sys/class/net/wlp58s0/statistics/rx_bytes", "r");
    fread(buf, sizeof(buf), 1, neo);
        bytedown = buf;
    pclose(neo);
    return bytedown;
}

std::string refreshByteUp(std::string byteup) {
    FILE *neo = new FILE;
    char buf[500] = { 0 };

    neo = popen("cat /sys/class/net/wlp58s0/statistics/tx_bytes", "r");
    fread(buf, sizeof(buf), 1, neo);
    byteup = buf;
    pclose(neo);
    return byteup;
}

std::string refreshName(std::string name) {
    FILE *neo = new FILE;
    char buf[500] = { 0 };

    neo = popen("iwgetid", "r");
    fread(buf, sizeof(buf), 1, neo);
    name = buf;
    name = name.substr(name.find("\"") + 1, name.length() - 1);
    name = name.erase(name.find("\""), name.length());
    pclose(neo);
    return name;
}

std::string refreshSpeed(std::string speed, std::string byteup, std::string bytedown) {
    long nb1 = std::stol(bytedown);
    long nb2 = std::stol(byteup);
    nb2 = (nb1 - nb2) / 1000;
    speed = std::to_string(nb2);
    speed.append(" Kb/s");
    return speed;
}

bool sysI::Network::update() {
    _coState = checkConnection();

    if (!_coState) {
        _Name = "Not connected";
        _byteUp = "0 k/s";
        _byteDown = "0 k/s";
        _Speed = "0 k/s";
        return false;
    } _byteDown = refreshByteDown(_byteDown);
    _byteUp = refreshByteUp(_byteUp);
    _Name = refreshName(_Name);
    _Speed = refreshSpeed(_Speed, _byteUp, _byteDown);

    _byteDown.erase(_byteDown.length() - 4, _byteDown.length());
    _byteUp.erase(_byteUp.length() - 4, _byteUp.length());
    _byteDown.append(" Kb");
    _byteUp.append(" Kb");
    return true;
}

bool sysI::Network::isEnable() {
    return this->_coState;
}

void sysI::Network::setActiveModule(bool value) {
    this->_coState = value;
}

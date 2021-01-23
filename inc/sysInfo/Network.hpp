//
// Created by flow on 23/01/2021.
//

#ifndef B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_NETWORK_HPP
#define B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_NETWORK_HPP

#include <string>
#include <iostream>
#include "IMonitorModule.hpp"

namespace sysI {
    class Network : public IMonitorModule{
        public:
            Network();
            ~Network();
            bool update() override;
            bool isEnable() override;
            void setActiveModule(bool value) override;
            std::string getByteDown() const;
	        std::string getByteUp() const;
            std::string getSpeed() const;
	        std::string getName() const;
            bool getCo() const;
	        bool checkConnection();
        private:
            bool _coState;
            std::string _byteDown;
            std::string _byteUp;
            std::string _Speed;
            std::string _Name;
    };
}

#endif //B_CPP_300_LYN_3_1_CPPRUSH3_MAXIME_PAYANT_NETWORK_HPP

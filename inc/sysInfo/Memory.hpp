/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Memory.hpp
*/

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <fstream>
#include <iostream>

namespace sysI
{


    class Memory {

        private:
            double _total;
            double _slab;
            double _cached;
            double _buffer;
            double _free;
            double _swapTotal;
            double _swapFree;

        public:
            typedef enum MemType_e {GB, MB, KB} MemType;

            static MemType memType;

            Memory() {};

            void checkMemoryInfo();
            double getTotalMem() const;
            double getUsedMem() const;
            double getTotalSwap() const;
            double getUsedSwap() const;

    };

} // namespace sysI

inline std::ostream& operator<<(std::ostream& os, const sysI::Memory& mem)
{
    os << "MemTotal:\t" << mem.getTotalMem() << std::endl
       << "MemUsed:\t" << mem.getUsedMem() << std::endl
       << "SwapTotal:\t" << mem.getTotalSwap() << std::endl
       << "SwapUsed:\t" << mem.getUsedSwap() << std::endl;
    return (os);
}

#endif // __MEMORY_H__
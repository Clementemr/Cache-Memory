#include "Memory.h"
#include "AddressDecoder.h"
#include "Set.h"
#include "PerformanceCounter.h"
#include <stdio.h>
#include <math.h>
#ifndef CACHE_H
#define CACHE_H


class Cache {

    private:
        Memory* m;
        int numBytes;
        int blockSize;
        int associativity;
        int numSets;
        Set** sets;
        AddressDecoder* addrDec;
        PerformanceCounter* pc;
        
    
    public:
        Cache(Memory* m, int numBytes, int blockSize, int associativity);
        unsigned char read(unsigned long address);
        void write(unsigned long address, unsigned char value);
        void setByte(unsigned long byte, unsigned char value);
        unsigned char getByte(unsigned long byte);
        void display();
        void getPerformance();
        

};

#endif
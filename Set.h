#include "AddressDecoder.h"
#include "Memory.h"
#include "PerformanceCounter.h"
#include "Block.h"
#include <stdio.h>
#ifndef SET_H
#define SET_H

class Set {

    private:
        int numBlocks;
        int blockSize;
        Memory* m;
        AddressDecoder* addrDec;
        Block** blocks;
        PerformanceCounter* pc;
        
    
    public:
        Set(int numBlocks, int blockSize, Memory* memPtr, AddressDecoder* addrDec);
        void setByte(unsigned long byte, unsigned char value);
        unsigned char getByte(unsigned long byte);
        void display();
        unsigned char read(unsigned long address);
        void write(unsigned long address, unsigned char value);
        PerformanceCounter* getPerformance();
        
        

};

#endif
#include "Memory.h"
#include "AddressDecoder.h"
#include <stdio.h>
#include <chrono>
#ifndef Block_H
#define Block_H

class Block {

    private:
        int size;
        unsigned char* data;
        Memory* m;
        AddressDecoder* addrDec;
        unsigned long tag;
        bool valid;
        bool dirty;
        long nanoSeconds;
    
    public:
        Block(int blockSize, Memory* ptr, AddressDecoder* addrDec);
        unsigned char read(int offset);
        void write(int offset, unsigned char newData);
        void display();
        unsigned long getTag();
        bool isValid();
        void eraseData();
        void writeBack(unsigned long address);
        void loadData(unsigned long address);
        unsigned long getAge();
        bool isDirty();

};

#endif
#include "AddressDecoder.h"
#include <stdio.h>

#ifndef MEMORY_H
#define MEMORY_H


class Memory {

    private:
        int size;
        unsigned char* bytes;


        
    
    public:
        Memory(int size);
        unsigned char getByte(unsigned long address);
        void setByte(unsigned long address, unsigned char value);
        void display();
        int getSize();
        unsigned char** getBytes();
        
        

};

#endif
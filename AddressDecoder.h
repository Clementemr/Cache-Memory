#include <stdio.h>
#ifndef ADDRESSDECODER_H
#define ADDRESSDECODER_H

class AddressDecoder {

    private:
        int tagLength;
        int blockOffsetLength;
        int setIndexLength;
        
    
    public:
        AddressDecoder(int tagLength, int setIndexLength, int blockOffsetLength);
        unsigned long getTag(unsigned long address);
        unsigned long getBlockOffset(unsigned long address);
        unsigned long getSetIndex(unsigned long address);
        void displayBits(unsigned long address);
        int getTagLength();
        

};

#endif
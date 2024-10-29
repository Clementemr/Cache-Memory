#include"AddressDecoder.h"

AddressDecoder::AddressDecoder(int tagLength, int setIndexLength, int blockOffsetLength){
    this->tagLength = tagLength;
    this->setIndexLength = setIndexLength;
    this->blockOffsetLength = blockOffsetLength;

    printf("tagLength: %d\n", this->tagLength);
    printf("setIndexLength: %d\n", this->setIndexLength);
    printf("blockOffsetLength: %d\n", this->blockOffsetLength);
    
}

unsigned long AddressDecoder::getTag(unsigned long address){
    unsigned long mask = 1;
    mask = mask << 31;
    unsigned long tag = 0;
    for(int i = 0; i < this->tagLength; i++){
        if((address & mask) != 0){
            tag = tag | mask;
        }
        mask = mask >> 1;
    }
    return tag >> (this->setIndexLength + this->blockOffsetLength);
}

unsigned long AddressDecoder::getBlockOffset(unsigned long address){
    unsigned long mask = 1;
    mask = mask << blockOffsetLength - 1;
    unsigned long blockOffset = 0;
    for(int i = 0; i < this->blockOffsetLength; i++){
        if((address & mask) != 0){
            blockOffset = blockOffset | mask;
        }
        mask = mask >> 1;
    }
    return blockOffset;
    
}

unsigned long AddressDecoder::getSetIndex(unsigned long address){
    unsigned long mask = 1;
    mask = mask << blockOffsetLength + setIndexLength - 1;
    unsigned long setIndex = 0;
    for(int i = 0; i < this->setIndexLength; i++){
        if((address & mask) != 0){
            setIndex = setIndex | mask;
        }
        mask = mask >> 1;
    }
    return setIndex >> blockOffsetLength;
    
}

void AddressDecoder::displayBits(unsigned long address){
    unsigned long mask = 1;
    mask = mask << 31;
    for(int i = 0; i < 32; i++){
        if((address & mask) == 0){
            printf("0");
        }else{
            printf("1");
        }
        mask = mask >> 1;
    }
    printf("\n");
}

int AddressDecoder::getTagLength(){
    return this->tagLength;
}


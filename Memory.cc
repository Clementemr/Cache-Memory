#include "Memory.h"


Memory::Memory(int size){
    this->bytes = new unsigned char[size];
    this->size = size;
    for(int i = 0; i < size; i++){
        this->bytes[i] = 255;
    }
}

unsigned char Memory::getByte(unsigned long address){
    return this->bytes[address];
}

void Memory::setByte(unsigned long address, unsigned char value){
    this->bytes[address] = value;
}

void Memory::display(){
    printf("Memory display\n");
    for(int i = 0; i < this->size; i++){
        if(i%16 == 0 && i != 0){
            printf("\n");
        }
        if(bytes[i]<16){
            printf("0");
        }
        printf("%x ", this->bytes[i]);
    }
    printf("\n");
    
}

int Memory::getSize(){
    return this->size;
}

unsigned char** Memory::getBytes(){
    return &this->bytes;
}



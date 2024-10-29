#include "Set.h"

Set::Set(int numBlocks, int blockSize, Memory* memPtr, AddressDecoder* addrDec){
    this->numBlocks = numBlocks;
    this->blockSize = blockSize;
    this->m = memPtr;
    this->addrDec = addrDec;
    this->blocks = new Block*[numBlocks];
    for(int i = 0; i < numBlocks; i++){
        this->blocks[i] = new Block(blockSize, memPtr, addrDec);
    }
    this->pc = new PerformanceCounter();
}

void Set::setByte(unsigned long byte, unsigned char value){
    
}

unsigned char Set::getByte(unsigned long byte){
    return 0;
}

void Set::display(){
    for(int i = 0; i < this->numBlocks; i++){
        this->blocks[i]->display();
    }
    
}

unsigned char Set::read(unsigned long address){
    this->pc->incrementAccesses();
    for(int i = 0; i < this->numBlocks; i++){
        if(this->blocks[i]->getTag() == this->addrDec->getTag(address)){
            if(this->blocks[i]->isValid() == true){
                printf("HIT\n");
                this->pc->incrementHits();
                return this->blocks[i]->read(this->addrDec->getBlockOffset(address));
            }
            
        }
    
    }
    for(int i = 0; i < this->numBlocks; i++){
        if(this->blocks[i]->isValid() == false){
            printf("MISS\n");
            this->pc->incrementMisses();
            this->blocks[i]->loadData(address);
            return this->blocks[i]->read(this->addrDec->getBlockOffset(address));
        }
    }
    printf("MISS\n");
    
    // LRU Eviction
    Block* oldest = this->blocks[0];
    for(int i = 0; i < this->numBlocks-1; i++){
        if (this->blocks[i]->getAge() < this->blocks[i+1]->getAge()){
            oldest = this->blocks[i+1];
        }
    }
    if(oldest->isDirty() == true){
        this->pc->incrementWriteBacks();
        oldest->writeBack(address);
    }
    this->pc->incrementMisses();
    oldest->eraseData();
    oldest->loadData(address);
    return oldest->read(this->addrDec->getBlockOffset(address));
}

void Set::write(unsigned long address, unsigned char value){
    this->pc->incrementAccesses();
    for(int i = 0; i < this->numBlocks; i++){
        if(this->blocks[i]->getTag() == this->addrDec->getTag(address)){
            if(this->blocks[i]->isValid() == true){
                printf("HIT\n");
                this->pc->incrementHits();
                this->blocks[i]->write(this->addrDec->getBlockOffset(address), value);
                return;
            }
            
        }
    
    }
    for(int i = 0; i < this->numBlocks; i++){
        if(this->blocks[i]->isValid() == false){
            printf("MISS\n");
            this->pc->incrementMisses();
            this->blocks[i]->loadData(address);
            this->blocks[i]->write(this->addrDec->getBlockOffset(address), value);
            return;
        }
    }
    printf("MISS\n");
    // LRU Eviction
    Block* oldest = this->blocks[0];
    for(int i = 0; i < this->numBlocks-1; i++){
        if (this->blocks[i]->getAge() < this->blocks[i+1]->getAge()){
            oldest = this->blocks[i+1];
        }
    }
    if(oldest->isDirty() == true){
        this->pc->incrementWriteBacks();
        oldest->writeBack(address);
    }
    this->pc->incrementMisses();
    oldest->eraseData();
    oldest->loadData(address);
    oldest->write(this->addrDec->getBlockOffset(address), value);
    return;
}

PerformanceCounter* Set::getPerformance(){
    return this->pc;
}


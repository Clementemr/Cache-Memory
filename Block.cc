#include "Block.h"



Block::Block(int blockSize, Memory* memPtr, AddressDecoder* addrDec){
    this->size = blockSize;
    this->data = new unsigned char[blockSize];
    for(int i = 0; i < blockSize; i++){
        this->data[i] = 0;
    }
    this->m = memPtr;
    this->tag = 0;
    this->valid = false;
    this->dirty = false;
    this->addrDec = addrDec;
    std::chrono::high_resolution_clock m_clock;
    this->nanoSeconds = std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();
}

unsigned char Block::read(int offset){
    this->nanoSeconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    return this->data[offset];
}

void Block::write(int offset, unsigned char newData){
    this->dirty = true;
    this->nanoSeconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    data[offset] = newData;
}

void Block::display(){
    printf("Tag: %lx ", this->tag);
    printf("Data: ");
    // for(int j=0;j<4;j++){
    //     for(int i = 7; i >= 0; i--){
    //     printf("%d", (data[j] >> i) & 1);
    //     }
    //     printf(" ");
    // }
    printf("Valid: %d ", this->valid);
    printf("Dirty: %d ", this->dirty);
    printf("Age: %ld\n", std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() - this->nanoSeconds);
    for(int i = 0; i < this->size; i++){
        printf("%x ", this->data[i]);
    }
    printf("\n");
}


unsigned long Block::getTag(){
    return this->tag;
}

bool Block::isValid(){
    return this->valid;
}

void Block::eraseData(){
    for(int i = 0; i < this->size; i++){
        this->data[i] = 0;
    }
}

void Block::loadData(unsigned long address){
    this->tag = this->addrDec->getTag(address);
    this->valid = true;
    int b = this->addrDec->getBlockOffset(address);
    for(int i = 0; i < this->size; i++){
        this->data[i] = this->m->getByte(address - b + i);
    }
}

unsigned long Block::getAge(){
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() - this->nanoSeconds;
}

void Block::writeBack(unsigned long address){
    this->dirty = false;
    int b = this->addrDec->getBlockOffset(address);
    for(int i = 0; i < this->size; i++){
        this->m->setByte(address - b + i, this->data[i]);
    }
}

bool Block::isDirty(){
    return this->dirty;
}

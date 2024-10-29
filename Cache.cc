#include "Cache.h"

Cache::Cache(Memory* m, int numBytes, int blockSize, int associativity) {
    this->m = m;
    this->numBytes = numBytes;
    this->blockSize = blockSize;
    this->associativity = associativity;
    this->numSets = (numBytes / blockSize)/associativity;
    this->addrDec = new AddressDecoder(32-log2(numSets)-log2(blockSize),log2(numSets),log2(blockSize));
    this->sets = new Set*[numSets];
    for(int i = 0; i < numSets; i++){
        this->sets[i] = new Set(associativity, blockSize, m, this->addrDec);
    }


}

unsigned char Cache::read(unsigned long address) {
    printf("Cache read: ");
    printf("%ld\n", address);
    // printf("bits:\n");
    // this->addrDec->displayBits(address);
    // printf("Tag: %lx\n", this->addrDec->getTag(address));
    // printf("Set Index: %lx\n", this->addrDec->getSetIndex(address));
    // printf("Block Offset: %lx\n", this->addrDec->getBlockOffset(address));
    return this->sets[this->addrDec->getSetIndex(address)]->read(address);
        
}

void Cache::write(unsigned long address, unsigned char value) {
    printf("Cache write: ");
    printf("%ld\n", address);
    this->sets[this->addrDec->getSetIndex(address)]->write(address, value);
}

void Cache::setByte(unsigned long byte, unsigned char value) {
        
}

unsigned char Cache::getByte(unsigned long byte) {
    return 0;
}

void Cache::display() {
    printf("CACHE DISPLAY\n");
    for(int i = 0; i < numSets; i++){
        printf("SET %x\n", i);
        this->sets[i]->display();
    }
    
}

void Cache::getPerformance() {
    int accesses = 0;
    int hits = 0;
    int misses = 0;
    int writeBacks = 0;
    for(int i = 0; i < numSets; i++){
        accesses += this->sets[i]->getPerformance()->getAccesses();
        hits += this->sets[i]->getPerformance()->getHits();
        misses += this->sets[i]->getPerformance()->getMisses();
        writeBacks += this->sets[i]->getPerformance()->getWriteBacks();
    }
    float missPerc = (float)misses/(float)accesses;
    float writeBackPerc = (float)writeBacks/(float)accesses;
    printf("\n");
    printf("PERFORMANCE\n");
    printf("Accesses: %d\n", accesses);
    printf("Hits: %d\n", hits);
    printf("Misses: %d\n", misses);
    printf("Writebacks: %d\n", writeBacks);
    printf("Miss Percentage: %f\n", missPerc);
    printf("Writeback Percentage: %f\n", writeBackPerc);
}







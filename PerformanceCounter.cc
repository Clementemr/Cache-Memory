#include "PerformanceCounter.h"


PerformanceCounter::PerformanceCounter(){
    this->hits = 0;
    this->misses = 0;
    this->reads = 0;
    this->writes = 0;
    this->accesses = 0;
    this->start_time = 0;
    this->end_time = 0;
    this->total_time = 0;
    this->writeBacks-0;
}

void PerformanceCounter::start(){
    this->start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void PerformanceCounter::stop(){
    this->end_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    this->total_time = this->end_time - this->start_time;
}

void PerformanceCounter::display(){


}

void PerformanceCounter::reset(){
    this->hits = 0;
    this->misses = 0;
    this->reads = 0;
    this->writes = 0;
    this->start_time = 0;
    this->end_time = 0;
    this->total_time = 0;
}

int PerformanceCounter::getHits(){
    return this->hits;
}

int PerformanceCounter::getMisses(){
    return this->misses;
}

int PerformanceCounter::getReads(){
    return this->reads;
}

int PerformanceCounter::getWrites(){
    return this->writes;
}

long PerformanceCounter::getStartTime(){
    return this->start_time;
}

long PerformanceCounter::getEndTime(){
    return this->end_time;
}

long PerformanceCounter::getTotalTime(){
    return this->total_time;
}

void PerformanceCounter::incrementHits(){
    this->hits++;
}

void PerformanceCounter::incrementMisses(){
    this->misses++;
}

void PerformanceCounter::incrementReads(){
    this->reads++;
}

void PerformanceCounter::incrementWrites(){
    this->writes++;
}

void PerformanceCounter::incrementAccesses(){
    this->accesses++;
}

int PerformanceCounter::getAccesses(){
    return this->accesses;
}

void PerformanceCounter::incrementWriteBacks(){
    this->writeBacks++;
}

int PerformanceCounter::getWriteBacks(){
    return this->writeBacks;
}



